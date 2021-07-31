#include <cstdio>
#define max 500

int graph[max][max];
int num_linking[max];
int color[max];
int colorable;

using namespace std;

int is_a_solution(int *a,int k,int n)
{
	return colorable;

}

void process(int *a,int k,int n)
{
	printf("colorable");
	
}

void candidate(int *a,int k,int n, int *c,int *nc)
{
	c[0]=0;
	c[1]=1;
	*nc=2;
	int i,j;
	for(i=0; i<n; 
	if(graph[i][j]==1){
		if(color[i] != color[j]){
			continue;
		else{
			break;
			coloarable=0;
			}
		}
	else
		continue;

}

void backtrack(int *a,int k,int n)
{
	int c[max];
	int nc;
	int i;
	if(is_a_solution(a,k,n))
		process(a,k,n);
	else{
		k++;
		candidate(a,k,n,c,&nc);
		for(i=0; i<nc; i++){
			a[k]=c[i];
			backtrack(a,k,n);
			if(finished)
				return;
			}
		}
}
int main()
{
	int i,j,n,a,b;
	scanf("%d",&n);
	for(i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		graph[a][b] =1;
		graph[b][a] =1;
		}
	backtrack(graph,0,n);
	return 0;
}

