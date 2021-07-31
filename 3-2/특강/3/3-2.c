#include <stdio.h>

typedef struct _queue{
	int x, y;
}QUE;

QUE que[50000];

int N;
int wp, rp;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int a[110][110];
int rec[110][110];

int bfs(){
	que[wp].x = 1;
	que[wp++].y = 1;	
	rec[1][1] = a[1][1];
	while(rp < wp){
		QUE q = que[rp++];
		if(q.x ==N && q.y == N) break;
		for(int i=0; i<4; i++){
			int nx = q.x + dx[i];
			int ny = q.y + dy[i];
			if(nx <1 || ny < 1 || nx >N || ny > N) continue;
			if(rec[ny][nx] > rec[q.y][q.x] + a[ny][nx]){
				que[wp++] = (QUE){nx, ny};
				rec[ny][nx] = rec[q.y][q.x] + a[ny][nx];
			}
		}
	}
	return rec[N][N];
}


int main(){

	scanf("%d", &N);
	int i,j;
	for(i=1; i<=N; i++){
		for(j=1; j<=N; j++){
			scanf("%1d", &a[i][j]);
			rec[i][j] = 999999;
		}
	}

	printf("%d", bfs());

	return 0;
}
