#include <stdio.h>

int que[50000];

int N,M;
int wp, rp;
int a[110][110];
int visit[110];
int rec[110];
int path[110];

int bfs(){
	que[wp++] = 1;
	rec[1] = a[1][1];
	while(rp < wp){
		int q = que[rp++];
		for(int i=1; i<=N; i++){
			if(a[q][i] == 0) continue;
			if(rec[i] > rec[q] + a[q][i]){
				que[wp++] = i;
				rec[i] = rec[q] + a[q][i];
				path[i]=q;
			}
		}
	}
	return rec[M];
}

void print(int n){
	if(n==0) return;
	print(path[n]);
	printf("%d ", n);
}
int main(){

	scanf("%d %d", &N, &M);
	int i,j;
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			scanf("%d", &a[i][j]);
		}
		rec[i] = 999999;
	}

	printf("%d\n", bfs());
	print(M);

	return 0;
}
