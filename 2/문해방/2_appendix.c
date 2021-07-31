/********************************/
/*     The Josephus Problem     */
/********************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct list_node {
	int value;
	struct list_node *next;
} NODE;

void print_list(NODE *);
NODE* head_insert(NODE *, int);
NODE* head_delete(NODE *);
NODE* tail_insert(NODE *, int);
NODE* tail_delete(NODE *);
void josephus(NODE *, int, int);

int main() {
	int n, m;
	NODE *jose = NULL;
	printf("The number of people : ");
	scanf("%d", &n);
	printf("The interval at which people are executed : ");
	scanf("%d", &m);
	josephus(jose, n, m);
	return 0;
}
void print_list(NODE *first) {
	

}

NODE* head_insert(NODE *first, int insert_data) {


}

NODE* head_delete(NODE *first) {


}

NODE* tail_insert(NODE *first, int insert_data) {


}

NODE* tail_delete(NODE *first) {


}

void josephus(NODE *jose, int n, int m) {


}