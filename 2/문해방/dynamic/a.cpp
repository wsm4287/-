#include <cstdio>

using namespace std;

int d[41];
int n;

int main()
{
	scanf("%d", &n);
	int i;
	d[0]= d[1] =1;
	d[2]=2;
	d[3]=3;
	for(i=4; i<=n; i++)
		d[i] = d[i-1]+d[i-2]+d[i-3];
	printf("%d", d[n]);	


}
