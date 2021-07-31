#include <cstdio>
#include <cmath>
using namespace std;

int sol;
int a[100];
bool finished = false;

int ok(int *a, int k, int n)
{
	return(k==n);
}

void process(int *a, int k, int n)
{
	sol++;
	printf("%d : ", sol);
	int i;
	for(i=1; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");

}

void candidate(int *a,int k,int n,int *c,int *nc)
{
	int i,j;
	int issafe;
	*nc=0;
	for(i=1; i<=n; i++){
		issafe=1;
		for(j=1; j<k; j++){
			if((a[j]==i)||(abs(j-k)==abs(a[j]-i))){
				issafe=0;
				break;
				}
			}
		if(issafe==1){
			c[*nc]=i;
			*nc= *nc+1;
			}
		}


}

void backtrack(int *a, int k, int n)
{
	int c[20];
	int nc;
	int i;
	if(ok(a,k,n))
		process(a,k,n);
	else{
		k++;
		candidate(a,k,n,c,&nc);
		for(i=0; i<nc; i++){
			a[k] = c[i];
			backtrack(a,k,n);
			if(finished)
				return;
			}
		}


}
int main()
{
	int x;
	scanf("%d", &x);
	backtrack(a,0,x);
	return 0;


}

