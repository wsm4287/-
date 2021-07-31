#include <cstdio>
#include <cmath>

#define max 100

using namespace std;


float freck[max][2];
int N;
float result;
int check[max];
float min[max];
int x;
int y[max];
int k=1;

float distance(int a,int b)
{
	return sqrt(pow(freck[a][0]-freck[b][0],2)+pow(freck[a][1]-freck[b][1],2));
}

void find(int x)
{
	int a;
	int i,j;
	for(i=0; i<N; i++)
		min[i] = distance(i,x);
	check[x] = 1;
	y[0]=x;
	for(i=0; i<N; i++){
		a= -1;
		for(j=0; j<N; j++){
			if(check[j])
				continue;
			if(a == -1|| min[a] > min[j])
				a=j;
			}
		check[a]=1;
		result = result + min[a];
		y[k++] = a;
		for(j=0; j<N; j++){
			if(check[j])
				continue;
			if(min[j] > distance(a,j))
				min[j] = distance(a,j);
			}
		}
							









}













int main()
{
	scanf("%d %d", &N, &x);
	int i;
	for(i=0; i<N; i++)
		scanf("%f %f", &freck[i][0], &freck[i][1]);
	find(x);
	for(i=0; i<N; i++)
		printf("%d\n", y[i]);
	printf("%0.2f", result);
}
