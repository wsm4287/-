#include <stdio.h>

int T, N;
int a[80];
int max;

void dfs(int k, int n){
	if(n==N-1) dfs(k+1, n+1);
	if(n>=N){
		if(max < k) max = k;
		return;
	}
	if(a[n]==2){
		dfs(k+1, n+1);
	}
	if(a[n] != a[n+1]){
		dfs(k+1, n+2);
		if(a[n] != a[n+2] && a[n+1] != a[n+2]) dfs(k+1, n+3);
	}
	return;


}

int main(){
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		for(int j=0; j<N; j++) scanf("%d", &a[j]);
		dfs(0,0);
		if(max == 0) printf("-1\n");
		else printf("%d\n", max);
		max = 0;
	}



}
