#include <cstdio>
#define max 10
using namespace std;

int R,C;
char a[max][max];

int is(char *a,int k,int n)
{


}

void process(char *a, int k,int n)
{
}
void candidate(char *a,int k,int n, int *c,int *nc)
{
}







void backtrack(char *a,int k, int n)
{
	char c[max];
	int nc;
	if(is(a,k,n))
		process(a,k,n);
	else{
		k++;
		candidate(a,k,n,c,&nc);
		for(int i=0; i<nc; i++){
			a[k] = c[i];
			backtrack(a,k,n);
			if(finished)
				return;
			}
		}
}



int main()
{
	scanf("%d %d". &R, &C);
	int i,j;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			scanf("%c", &a[i][j]);
			}
		}
	backtrack(a,0,5);


}








