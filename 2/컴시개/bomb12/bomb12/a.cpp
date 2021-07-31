#include <cstdio>

using namespace std;

unsigned main(int a1)
{
  char *v1; // r12
  int *v2; // r13
  signed int v3; // er14
  signed int v4; // ebx
  int v5; // rsi
  int *v6; // rdx
  signed int v7; // eax
  int v8; // ecx
  int v9; // rbx
  int *v10; // rax
  int v11; // rcx
  int v12; // rdx
  signed int v13; // ebp
  int v15[6]; // [rsp+0h] [rbp-88h]
  char v16; // [rsp+18h] [rbp-70h]
  int v17[5]; // [rsp+20h] [rbp-68h]
  char v18; // [rsp+48h] [rbp-40h]
  unsigned __int64 v19; // [rsp+58h] [rbp-30h]

  v19 = __readfsqword(0x28u);
  read_six_numbers(a1, v15);
  v1 = (char *)v15;
  v2 = v15;
  v3 = 0;
  while ( 1 )
  {
    if ( (unsigned int)(*v2 - 1) > 5 )
      printf("%d %d",a1, v15);
    if ( ++v3 == 6 )
      break;
    v4 = v3;
    do
    {
      if ( *v2 == v15[v4] )
        printf("%d %d",a1, v15);
      ++v4;
    }
    while ( v4 <= 5 );
    ++v2;
  }
  do
  {
    *(_DWORD *)v1 = 7 - *(_DWORD *)v1;
    v1 += 4;
  }
  while ( &v16 != v1 );
  v5 = 0LL;
  do
  {
    v8 = v15[v5];
    v7 = 1;
    v6 = &node1;
    if ( v8 > 1 )
    {
      do
      {
        v6 = (_QWORD *)v6[1];
        ++v7;
      }
      while ( v7 != v8 );
    }
    v17[v5] = (__int64)v6;
    ++v5;
  }
  while ( v5 != 6 );
  v9 = v17[0];
  v10 = v17;
  v11 = v17[0];
  do
  {
    v12 = v10[1];
    *(_QWORD *)(v11 + 8) = v12;
    ++v10;
    v11 = v12;
  }
  while ( &v18 != (char *)v10 );
  *(_QWORD *)(v12 + 8) = 0LL;
  v13 = 5;
  do
  {
    if ( *(_DWORD *)v9 < **(_DWORD **)(v9 + 8) )
      explode_bomb(a1, &v18);
    v9 = *(_QWORD *)(v9 + 8);
    --v13;
  }
  while ( v13 );
  return __readfsqword(0x28u) ^ v19;
}

