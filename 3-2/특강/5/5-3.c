#include <stdio.h>

int N, M;
int a[15][15];
int color[15];

int check(int n, int cl){
	for(int i=0; i<N; i++){
		if(a[n][i] ==1 && color[i] == cl) return 0;
	}
	return 1;
}

int DFS(int n){

	if(n==N) return 1;
	for(int i=0; i<M; i++){
		if(check(n,i)){
			color[n] = i;
			if(DFS(n+1)) return 1;
			color[n] = 0;
		}

	}

	return 0;

}


int main(){

	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<=i; j++){
			scanf("%d", &a[i][j]);
		}
	}
	if(DFS(0)){
		for(int i=0; i<N; i++) printf("%d ", 1+color[i]);

	}
	else printf("-1");
	return 0;

}
