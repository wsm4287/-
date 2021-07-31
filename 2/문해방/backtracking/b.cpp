#include <cstdio>
#include <algorithm>

using namespace std;

bool finished = false;
int a[20];
int N;
int arr[20];
int x;
int S;

int is_solution(int *a, int k,int n)
{
	return (k==n);
}
void process(int *a,int k,int n)
{
	int sum=0;
	int i;
	for(i=1; i<=n; i++){
		if(arr[i] ==1)
			sum +=a[i];
	}
	if(sum ==S)
		x++;
}
void condidate(int *a, int k,int n,int *c,int *nc)
{
	c[0] = 1;
	c[1] = 0;
	*nc =2;
}
void backtracking(int *a,int k,int n)
{
	int c[20];
	int nc;
	int i;
	if(is_solution(a,k,n))
		process(a,k,n);
	else{
		k++;
		condidate(a,k,n,c,&nc);
		for(i=0; i<nc; i++){
			arr[k]=c[i];
			backtracking(a,k,n);
			if (finished) return;
		}
	}
}
int main()
{
	scanf("%d %d",&N,&S);
	int i;
	for(i=1; i<=N; i++)
		scanf("%d", &a[i]);
	backtracking(a,0,N);
	printf("%d",x);

}


