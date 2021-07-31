#include <cstdio>
#define max 1000

using namespace std;

int n;
int D[max];

int main()
{
	scanf("%d", &n);
	D[0]=0;
	D[1]=1;
	D[2]=2;
	int i;
	for(i=3; i<=n; i++)
		D[i] =D[i-1]+D[i-2];
	printf("%d", D[n]);
	






}
