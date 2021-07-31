#include <cstdio>
#include <algorithm>
#include <cstring>

#define Max 100

using namespace std;

char a[Max];
char b[Max];
int graph[Max][Max];

int main()
{
	scanf("%s", a);
	scanf("%s", b);
	int x,y;
	x = strlen(a);
	y = strlen(b);
	int i,j;
	for(i=1; i<=x; i++){
		for(j=1; j<=y; j++){
			if(a[i-1] == b[j-1])
				graph[i][j] = graph[i-1][j-1] +1;
			else
				graph[i][j] = max(graph[i][j-1],graph[i-1][j]);
			}
		}
	printf("%d", graph[x][y]);


}
