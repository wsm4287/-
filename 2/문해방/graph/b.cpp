#include <cstdio>

#define max 100

using namespace std;

int friends[max][max];
int num[max];
int f_list[max];
int N;
int X;


void find(int x,int y)
{
	int i;
	int next;

	for(i=0; i<num[x]; i++){
		next = friends[x][i];
		f_list[next] = true;
		}
	if(y==1)
		return;
	else{
		for(i=0; i<num[x]; i++){
			next = friends[x][i];
			find(next,y-1);
			}
 	}
	

}






int main()
{
	int i,a,b,m;
	scanf("%d %d", &N, &m);
	for(i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		friends[a][num[a]++]=b;
		friends[b][num[b]++]=a;
	}
	find(2,3);
	f_list[2]=0;
	for(i=1; i<=N; i++)
		printf("%d",f_list[i]);

	
}
