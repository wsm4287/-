#include <cstdio>
#define max 100

using namespace std;

int x[max];
int s;
int cnt;
int t;

bool finished(int *a, int k,int n)
{
	if(t ==s)
		return 1;
	else 
		return 0;
	
}

int ok(int *a, int k,int n)
{
	return(k==n);
}

void process(int *a, int k, int n)
{
	int sum=0;
	int i;
	for(i=1; i<=n; i++){
		if(x[i] == 1)
			sum = sum + a[i];
		}
	if(sum ==s){
		cnt++;
		t =s;
		for(i=1; i<=n; i++)
			printf("%d ",x[i]);
		printf("\n%d\n", sum);
		}
}

void candidate(int *a, int k, int n, int *c, int *nc)
{
	c[0] =0;
	c[1] =1;
	*nc =2;
}

void backtrack(int *a, int k,int n)
{	
	int c[max];
	int nc;
	int i;
	if(ok(a,k,n))
		process(a,k,n);
	else{
		k++;
		candidate(a,k,n,c,&nc);
		for(i=0; i<nc; i++){
			x[k] = c[i];
			backtrack(a,k,n);
			if(finished(a,k,n))
				return;
			}
		
		}
}
int main()
{
	int N;
	scanf("%d %d", &N, &s);	
	int a[N];
	int i;
	for(i=1; i<=N; i++)
		scanf("%d", &a[i]);
	backtrack(a,0,N);
	printf("%d\n", cnt);


}

