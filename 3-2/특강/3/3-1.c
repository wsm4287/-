#include <stdio.h>

typedef struct _queue{
	int x, y, z, time;
}QUE;

QUE que[50000];

int M, N;
int wp, rp;

int dx[] = {0,1,-1,0,0};
int dy[] = {0,0,0,1,-1};
int dz[5][2] = { {0,0}, {4, 3}, {3, 4},{1, 2}, {2, 1} };

int a[110][110];
int visit[5][110][110];
int x1, x2, y1, y2, z1, z2;

int bfs(){
	que[wp].x = x1;
	que[wp].y = y1;	
	que[wp].z = z1;
	que[wp++].time = 0;
	visit[z1][y1][x1] = 1;
	while(rp < wp){
		QUE q = que[rp++];
		if(q.x == x2 && q.y == y2 && q.z == z2) return q.time;
		for(int i=1; i<4; i++){
			int nx = q.x + dx[q.z]*i;
			int ny = q.y + dy[q.z]*i;
			if(nx <1 || ny < 1 || nx >N || ny > M) break;
			if(a[ny][nx] ==1) break;
			if(visit[q.z][ny][nx] ==0){
				que[wp++] = (QUE){nx, ny, q.z,q.time+1};
				visit[q.z][ny][nx] = 1;
			}
		}
		for(int i=0; i<2; i++){
			int nz =dz[q.z][i];
			if(visit[nz][q.y][q.x] ==0){
				que[wp++] = (QUE) { q.x, q.y, nz, q.time+1};
				visit[nz][q.y][q.x] = 1;
			}
		}
	}

	return 0;
}


int main(){

	scanf("%d %d", &M, &N);
	int i,j;
	for(i=1; i<=M; i++){
		for(j=1; j<=N; j++) scanf("%d", &a[i][j]);
	}
	scanf("%d %d %d %d %d %d", &y1, &x1, &z1, &y2, &x2, &z2);

	printf("%d", bfs());

	return 0;
}
