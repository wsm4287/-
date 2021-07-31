#include <stdio.h>

int N;
int a[22];
int min = 9999;

int minus(int b, int c){
	if(b >= c) return b-c;
	else return c-b;
}

void dfs(int k, int k1, int k2, int b1, int b2){
	if(k1 > N/2) return;
	if(k2 > N/2) return;
	if(k == N && k1 == N/2 && k2 == N/2){
		if(min > minus(b1,b2)) min = minus(b1,b2);
		return;
	}
	dfs(k+1, k1+1, k2, b1+a[k], b2);
	dfs(k+1, k1, k2+1, b1, b2 + a[k]);

}



int main(){

	scanf("%d", &N);
	for(int i=0; i<N; i++) scanf("%d", &a[i]);
	dfs(0,0,0,0,0);
	printf("%d", min);
	return 0;
}
