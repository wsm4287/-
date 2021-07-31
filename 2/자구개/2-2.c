#include <stdio.h>
#include <stdlib.h>

int N;
int depth=0;

typedef struct A {
	int q;
	struct A* left;
	struct A* right;
} a;

a* insert(a *x, int t){
	a* temp;
	temp =(a*)malloc(sizeof(a));
	temp-> q = t;
	temp ->left=NULL;
	temp->right=NULL;
	if(x ==NULL){
		return temp;
	}
	if(t < x->q)
		x->left = insert(x->left,t);
	else if(t >= x->q)
		x->right = insert(x->right,t);
	
	return x;
}

int max(a *x){
	if(x==NULL)
		return 0;
	else{
		int l = max(x->left);
		int r = max(x->right);
		if(l>r)
			return(l+1);
		else
			return(r+1);
	}
}

int main() {
	scanf("%d", &N);
	a *first = NULL;
	int i;
	for(i=0; i<N; i++){
		int t;
		scanf("%d", &t);
		first = insert(first,t);
	}
	
	depth = max(first);
	
	printf("%d", depth-1);
}