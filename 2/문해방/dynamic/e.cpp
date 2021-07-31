#include <cstdio>
#include <algorithm>

using namespace std;

int graph[100][100];
int N,W;
int item[100][2];

int main(){

	scanf("%d %d", &N, &W);
	int i;
	for(i=0; i<N; i++)
		scanf("%d %d", &item[i][0], &item[i][1]);
	int j;
	for(i=1; i<=N; i++){
		for(j=1; j<=W; j++){
			if(j< item[i-1][0])
				graph[i][j] = graph[i-1][j];
			else
graph[i][j] = max(max(graph[i-1][j], graph[i-1][j-item[i-1][0]]+item[i-1][1]),graph[i][j-item[i-1][0]]+item[i-1][1]);
			}
		}

	for(i=0; i<=N; i++){
		printf("\n");
		for(j=0; j<=W; j++)
			printf("%d ", graph[i][j]);
			}








}
