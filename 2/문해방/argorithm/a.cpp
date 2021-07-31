#include <cstdio>
#include <cmath>
#include <queue>

#define max 100

using namespace std;

double prim[max][2];
int check[max];
float result;
float Min[max]; 
int n,s;
int x[max];
float d[max][max];
queue<pair<int,int>> q;

float distance(int i, int j)
{
	return sqrt(pow((prim[i][0]-prim[j][0]),2)+pow((prim[i][1]-prim[j][1]),2));
}

void find(int s)
{
	int i;
	int j;
	for(i=0; i<n; i++)
		Min[i] = distance(s,i);
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)	
			d[i][j]=distance(i,j);
		}
	d[2][3] =1000000;
	d[3][2] =1000000;
	Min[3] = 1000000;
	check[s] =1;
	x[0]=s;
	int k=1;
	int a;

	for(i=0; i<n; i++){
		a=-1;
		for(j=0; j<n; j++){
			if(check[j])
				continue;
			if(a==-1||Min[a] > Min[j])
				a=j;
			}
		check[a]=1;
		q.push(make_pair(x[k-1],a));
		x[k++]=a;
		result = result + Min[a];
		for(j=0; j<n; j++){
			if(Min[j] > d[a][j])
				Min[j] = d[a][j];
				}
		}
}








int main()
{
	scanf("%d", &n);
	scanf("%d", &s);
	int i;
	for(i=0; i<n; i++){
		scanf("%lf %lf", &prim[i][0], &prim[i][1]);
		}
	find(s);
	while(!q.empty()){
		printf("%d %d\n", q.front().first, q.front().second);
		q.pop();
			}
		
			
	printf("%0.2f", result);




}
