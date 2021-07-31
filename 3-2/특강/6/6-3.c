#include <stdio.h>

int N, max;
int km[60];
int tm[60];
int tt=9999;

void dfs(int n, int time){
	if(n == N+1){
		if(tt > time) tt = time;
		return;
	}
	int length =0;
	for(int i=n+1; i<=N+1; i++){
		length += km[i];
		if(length > max) break;
		if(tt > time+tm[i]) dfs(i, time + tm[i]); 
	}


}



int main(){
	scanf("%d %d", &max, &N);
	for(int i=1; i<=N+1; i++) scanf("%d", &km[i]);
	for(int i=1; i<=N; i++) scanf("%d", &tm[i]);
	dfs(0,0);

	printf("%d", tt);

}



