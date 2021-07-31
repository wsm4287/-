#include <cstdio>
#define max 10000
using namespace std;


int graph[max][max];
int distance[max][max];
int n;

int main()
{
	int e,x;
	scanf("%d %d %d", &n,&e,&x);
	n++;

	
	int i,j,k;
	int a,b,s;
	for(i=0; i<e; i++){
		scanf("%d %d %d", &a,&b,&s);
		graph[a][b]=s;
		}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			if(graph[i][j] !=0)
				distance[i][j] = graph[i][j];
			else
				distance[i][j] = 10000000;
			}
		}

	for(k=0; k<n; k++){
		for(j=0; j<n; j++){
			for(i=0; i<n; i++){
				if(distance[i][j] > distance[i][k] + distance[k][j])
					distance[i][j] = distance[i][k]+distance[k][j];
				}
			}
		}
	for(j=1; j<n; j++){
		if(distance[x][j] != 10000000) printf("%d\n",distance[x][j]);
		else printf("INF\n");
		}
		


}
