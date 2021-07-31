#include <cstdio>
#define max 100
using namespace std;

int n;
int a,b;
int fibonacci[max];


int main()
{
	scanf("%d", &n);
	fibonacci[0] =0;
	fibonacci[1]=1;
	fibonacci[2]=1;
	int i;
	for(i=3; i<=n; i++)
		fibonacci[i] = fibonacci[i-1]+fibonacci[i-2];
	
	printf("%d", fibonacci[n]);



}
