#include <stdio.h>

int T, N, K;

int d[22];
int ok;

int check(int n, int sum)    
{
	if(sum == K) return 1;
	if(sum > K) return 0;
	if(n == N) return 0;
	if(check(n+1, sum+d[n])==1) return 1;
	if(check(n+1, sum)==1) return 1;
	return 0;
}

int main(void)
{
	int i,j;
	scanf("%d", &T);
	for(i=0; i<T; i++){
		scanf("%d %d", &N, &K);
		for(j=0; j<N; j++) scanf("%d", &d[j]);
		ok = check(0, 0);
		if(ok==1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
	
}
