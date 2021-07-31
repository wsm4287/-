#include <cstdio>
#define max 500

using namespace std;

int graph[max][max];
int visited[max];
int N,S,A,B;
int ans;

void dfs(int A, int B,int l)
{
	int i;
	if(A==B){
		if(ans < l) ans=l;
		return;
		}
	else{
		for(i=0; i<N; i++){
			if((visited[i] ==0) && (graph[A][i]!=0)){
				visited[i] =1;
				dfs(i,B,l+graph[A][i]);
				visited[i] =0;
				}
			}
		}



}



int main()
{
	scanf("%d %d", &N, &S);
	int i,j;
	int a,b,c;
    scanf("%d", &A);
	for (i=0; i<S; i++){
		scanf("%d %d %d", &a,&b,&c);
		graph[a][b]=c;
		}
	visited[A]=1;
	for(i=0; i<N; i++){
        dfs(A,i,0);
        printf("%d\n", ans);
        ans=0;
	}



}
