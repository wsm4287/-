#include <cstdio>
#define max 100

using namespace std;

int graph[max][max];
int distance[max][max];
int v;
int e;

int main()
{
	scanf("%d %d", &v, &e);
	int i,j;
	int a,x,c;
	for(i=0; i<v; i++) for(j=0; j<v; j++) distance[i][j]=10;
	for(j=0; j<e; j++){
		scanf("%d %d %d", &a,&x,&c);
		graph[a][x]=c;
		distance[a][x]=c;
		graph[x][a]=c;	
		distance[x][a]=c;
		}
	int k;
	for(k=0; k<v; k++){
		for(i=0; i<v; i++){
			for(j=0; j<v; j++){
				if(distance[i][j] > distance[i][k]+ distance[i][j])
					distance[i][j] = distance[i][k]+distance[k][j];
				}
			}
		}
	


	for(j=0; j<v; j++) if(distance[1][j]!=10) printf("%d\n", distance[1][j]);











}
