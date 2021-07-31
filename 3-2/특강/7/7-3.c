#include <stdio.h>

int M,N;
int a[15][15];

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1}; 
int wp, rp;

typedef struct _QUE{
	int x, y;
}que;

que Q[1000];
int max, cnt;

void bfs(int x1, int y1, int c){
	que q;
	Q[wp++] = (que) { x1, y1};
	a[y1][x1] = 0;
	while(rp < wp){
		cnt++;
		q = Q[rp++];
		for(int i=0; i<8; i++){
			int nx = q.x + dx[i];
			int ny = q.y + dy[i];
			if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if(a[ny][nx] == 1){
				Q[wp++] = (que) {nx, ny};
				a[ny][nx] = 0;
			}


		}
	
	}

}



int main(){

	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++) scanf("%d", &a[i][j]);
	}
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cnt = 0;
			if(a[i][j] == 1) bfs(j,i,0);
			if(max < cnt) max = cnt;
		}
	}
	printf("%d", max);
	return 0;

}
