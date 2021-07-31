#include <cstdio>
#define max 100

using namespace std;

int graph[max][max];
int many[max];
int link[max];

void find(int x, int y)
{
	int i;
	for(i=0; i<many[x]; i++)
		link[graph[x][i]] =true;
	y--;
	int next;
	if(y >=1){
		for(i=0; i<many[x]; i++){
			next = graph[x][i];
			find(next,y);
			}
		}
	else
		return;
		


}

int main()
{
	int N,s;
	int a,b;

	scanf("%d %d", &N, &s);
	int i;
	for(i=0; i<s; i++){
		scanf("%d %d",&a,&b);
		graph[a][many[a]++]=b;
		graph[b][many[b]++]=a;
		}
	int x,y;	
	scanf("%d %d",&x,&y);
	find(x,y);
	link[x] =0;
	int sum=0;
	for(i=0; i<=N; i++)
		sum = sum+ link[i];
	printf("%d", sum);
	


}
