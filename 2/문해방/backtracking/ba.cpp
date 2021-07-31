#include <cstdio>
#include <cmath>
#include <cstdlib>
#define max 500
using namespace std;




int x;

int is(int *a, int n, int k)
{
	return(n==k);
}


void process(int *a, int n, int k)
{
	int i;
	printf("%d : ", x);
	for(i=1; i<=n; i++){
		printf("%d ", a[i]);
		}
	printf("\n");
	x++;
}

void candidate(int *a, int n,int k, int *c, int *nc)
{
	*nc =0;
	int issafe;
	int i,j;
	for(i=1; i<=n; i++){
		issafe =1;
		for(j=1; j<k; j++){
			if((a[j] == i)||(abs(j-k) == abs(a[j]-i))){
				issafe =0;
				break;
			}
		}
		if(issafe){
			c[*nc]=i;
			*nc =*nc+1;
			}
	}



}


void backtrack(int *a, int n, int k)
{
	int nc;
	int c[20];
	int i;
	if(is(a,n,k))
		process(a,n,k);
	else{
		k++;
		candidate(a,n,k,c,&nc);
		for(i=0; i<nc; i++){
			a[k] = c[i];
			backtrack(a,n,k);
			}
	}

}


int main()
{
	int a[8]={0,0,0,0,0,0,0,0};
	backtrack(a,8,0);
	return 0;



}

