#include <cstdio>
#include <math.h>

using namespace std;
int a[100];
int sol=0;
bool finished = false;


int is_a_solution(int *a, int k,int n)
{
	return(k ==n);
}

void process(int *a,int k,int n)
{
	sol++;
	int i;
	printf("%d : ",sol);
	for(i=1; i<=n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void candidate(int *a,int k,int n,int *c,int *nc)
{
	*nc=0;
	int issafe;
	int i,j;
	for(i=1; i<=n; i++){
		issafe =1;
		for(j=1; j<k; j++){
			if((a[j]==i)||(abs(j-k) == abs(a[j]-i))){
				issafe=0;
				break;
				}	
			}
		if(issafe){
			c[*nc] = i;
			*nc =*nc+1;
			}
		}


}

void backtrack(int*a, int k,int n)
{
	int nc;
	int c[20];
	int i;
	if(is_a_solution(a,k,n))	
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
	backtrack(a,0,15);
	return 0;
}
		
			
