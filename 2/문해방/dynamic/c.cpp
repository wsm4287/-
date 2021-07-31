#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


#define max 100

char a[max];
char b[max];

int graph[max][max];

int main()
{
	scanf("%s",a);
	scanf("%s",b);
	int x,y;
	x = strlen(a);
	y = strlen(b);
	puts(a);
	puts(b);
	printf("%d %d\n", x,y);
	int i,j;
	for(i=0; i<=x; i++)
		graph[i][0] =i;
	for(i=1; i<=y; i++)
		graph[0][i] = i;
	for(i=1; i<=x; i++){
		for(j=1; j<=y; j++){
			if(a[i-1] == b[j-1])
				graph[i][j] = graph[i-1][j-1];
			else
			graph[i][j] = min(min(graph[i-1][j-1],graph[i-1][j]),graph[i][j-1])+1;

			}
		}
	for(i=0; i<=x; i++){
			printf("\n");
		for(j=0; j<=y; j++)
			printf("%d ", graph[i][j]);
			}



}
