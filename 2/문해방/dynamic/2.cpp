#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define Max 100

using namespace std;

char a[Max];
char b[Max];
int graph[Max][Max];
char c[Max];

int main()
{
	scanf("%s", a);
	scanf("%s", b);
	int x = strlen(a);
	int y = strlen(b);
	int i,j;
	for(i=0; i<x; i++)
		graph[0][i] =0;
	for(i=0; i<y; i++)
		graph[i][0] =0;

	for(i=1; i<=x; i++){
		for(j=1; j<=y; j++){
			if(a[i-1] == b[j-1]){
				graph[i][j] = graph[i-1][j-1] +1;
				}
			else
				graph[i][j] = max(graph[i-1][j], graph[i][j-1]);
			}
		}
	for(i=0; i<=x; i++) {
		printf("\n");
		for(j=0; j<=y; j++)
				printf("%d ", graph[i][j]);
					
			}

	i--;
	j--;
	int x1 = x;
	int y1 = y;
	while(i>0 && j>0){
	while(graph[i][y1] == graph[x1][y1])
		i--;	
	if(i==x){
		while(graph[x1][j] == graph[x1][y1])
			j--;
		c[graph[x1][y1]-1] = b[j];
		x1 = i-1;
		y1 = j;
		}
	else{
		c[graph[x1][y1]-1] = a[i];
		x1 = i;
		y1 = j-1;
		}

	}

	c[graph[x][y]]=0;
	printf("\n%s", c);



}
