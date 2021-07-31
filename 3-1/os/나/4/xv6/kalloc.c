// Physical memory allocator, intended to allocate
// memory for user processes, kernel stacks, page table pages,
// and pipe buffers. Allocates 4096-byte pages.

#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"
#include "proc.h"
#include "x86.h"

void freerange(void *vstart, void *vend);
extern char end[]; // first address after kernel loaded from ELF file
                   // defined by the kernel linker script in kernel.ld

struct run {
  struct run *next;
};

struct {
  struct spinlock lock;
  int use_lock;
  struct run *freelist;
} kmem;


extern char bitm[4096];

struct page pages[PHYSTOP/PGSIZE];
struct page *page_lru_head;
int SS;


struct spinlock lru;

// Initialization happens in two phases.
// 1. main() calls kinit1() while still using entrypgdir to place just
// the pages mapped by entrypgdir on free list.
// 2. main() calls kinit2() with the rest of the physical pages
// after installing a full page table that maps them on all cores.
void
kinit1(void *vstart, void *vend)
{
  initlock(&kmem.lock, "kmem");
  kmem.use_lock = 0;
  freerange(vstart, vend);
}

void
kinit2(void *vstart, void *vend)
{
  freerange(vstart, vend);
  kmem.use_lock = 1;
}

void
freerange(void *vstart, void *vend)
{
  char *p;
  p = (char*)PGROUNDUP((uint)vstart);
  for(; p + PGSIZE <= (char*)vend; p += PGSIZE)
    kfree(p);
}
// Free the page of physical memory pointed at by v,
// which normally should have been returned by a
// call to kalloc().  (The exception is when
// initializing the allocator; see kinit above.)
void
kfree(char *v)
{
  struct run *r;

  if((uint)v % PGSIZE || v < end || V2P(v) >= PHYSTOP){
    panic("kfree");
    }

  // Fill with junk to catch dangling refs.
  memset(v, 1, PGSIZE);

  if(kmem.use_lock)
    acquire(&kmem.lock);
  r = (struct run*)v;
  r->next = kmem.freelist;
  kmem.freelist = r;
  if(kmem.use_lock)
    release(&kmem.lock);
}

static pte_t * walkpgdir(pde_t *pgdir, const void *va, int alloc)
{
  pde_t *pde;
  pte_t *pgtab;

  pde = &pgdir[PDX(va)];
  if(*pde & PTE_P){
	pgtab = (pte_t*)P2V(PTE_ADDR(*pde));
  } else{
	if(!alloc || (pgtab = (pte_t*)kalloc()) ==0)
	  return 0;
	memset(pgtab, 0 ,PGSIZE);
	*pde = V2P(pgtab) | PTE_P | PTE_W | PTE_U;
    }
   return &pgtab[PTX(va)];
}

// Allocate one 4096-byte page of physical memory.
// Returns a pointer that the kernel can use.
// Returns 0 if the memory cannot be allocated.
char*
kalloc(void)
{
  struct run *r;
  try_again :
  while(SS);
  if(kmem.use_lock)
    acquire(&kmem.lock);
  r = kmem.freelist;
  if(r){
    kmem.freelist = r->next;
 } else{
    SS = 1;
    acquire(&bitmap);
    int i=0;
    while(bitm[i])
	i++;
    release(&bitmap);
    acquire(&lru);
    struct page *p;
    p = page_lru_head;
    if(!p)
	panic("OOM ERROR\n");
    pte_t *pte;
    pte = walkpgdir(p->pgdir, (void *)(p->vaddr), 0);  
    while((*pte &PTE_A)==PTE_A){ 
	*pte = *pte - PTE_A;
	p = p -> next;
	pte = walkpgdir(p->pgdir, (void *)p->vaddr, 0);
    }
    release(&lru);
    char *mem = P2V(PTE_ADDR(*pte));
    if(kmem.use_lock)
     release(&kmem.lock);
    swapwrite(mem, i);

    if(kmem.use_lock)
     acquire(&kmem.lock);
    SS = 0;
    acquire(&lru);
    acquire(&bitmap);
    bitm[i] = 1;
    release(&bitmap);
    lcr3(V2P(p->pgdir));
    p-> prev ->next = p-> next;
    p-> next -> prev = p-> prev; 
    page_lru_head = p -> next;
    p -> next = 0;
    p -> prev = 0;
    p -> pgdir = 0;
    p -> vaddr = 0;
    *pte = *pte & 0x00000FFF;
    *pte = *pte & ~PTE_P;
    *pte = *pte | i<<12;
    release(&lru);
    if(kmem.use_lock)
      release(&kmem.lock);
    kfree(mem);
    goto try_again;
  }
 if(kmem.use_lock)
    release(&kmem.lock);
  return (char*)r;
}

void mklist(pte_t *pgdir, char *vaddr, uint pa)
{ 
  acquire(&lru);
  struct page *p;
  p = &pages[pa/PGSIZE];
  p->pgdir = pgdir;
  p->vaddr = vaddr;
  if(!page_lru_head){
	page_lru_head = p;
	page_lru_head -> next = p;
	page_lru_head -> prev = p;
  }
  else{
	p -> prev = page_lru_head -> prev;
	p -> next = page_lru_head;
  }
  page_lru_head -> prev -> next = p;
  page_lru_head -> prev = p;
  release(&lru);
}

void dllist(pte_t *pgdir, char *vaddr)
{
   acquire(&lru);
   struct page *p = page_lru_head;
   if(!p){
     release(&lru);
     return;
   }
   while(1){
	if(p-> pgdir == pgdir && p->vaddr == vaddr){
		p -> prev -> next = p -> next;
		p -> next -> prev = p -> prev;
		if(p == page_lru_head)
			page_lru_head = p->next;
	}
    p = p->next;
    if(p == page_lru_head) break;
  }
  release(&lru);

} 

int page_handler(uint rcr2)
{
   pte_t *pte;
   pte = walkpgdir(myproc()->pgdir, (char*)rcr2, 0);
   int a = *pte & 0xFFFFF000;
   a = a>>12;

   if(pte && !(*pte & PTE_P)){
       char *mem;
       mem = kalloc();
       swapread(mem, a);
       *pte = *pte - (a<<12);
       *pte = *pte | ((uint)V2P((uint)mem) & 0xFFFFF000 );
       *pte = *pte | PTE_P | PTE_A;
       mklist(myproc()->pgdir, (char *)PGROUNDDOWN((uint)rcr2), V2P(mem));
       acquire(&bitmap);
       bitm[a] = 0;
       release(&bitmap);
       return 0;
   } 
   return -1;

}
