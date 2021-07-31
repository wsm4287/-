#include <stdio.h>

int X, Y;
int a[110][110];

typedef struct _que{
	int x, y, time;
}QUE;
QUE que[10000];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int rp, wp;
int a1,b1;

int find(){
	que[wp].x = a1;
	que[wp].y = b1;
	que[wp++].time = 0;
	a[b1][a1] = 0;
	while(rp <wp){
		QUE q = que[rp++];
		for(int i=0; i<4; i++){
			int nx = q.x+dx[i];
			int ny = q.y+dy[i];
			if(nx <1 || nx > X || ny < 1 || ny > Y) continue;
			if(a[ny][nx] == 1){
				que[wp].x = nx;
				que[wp].y = ny;
				que[wp++].time = q.time+1;
				a[ny][nx] = 0;
			}
		}
	}
	return que[wp-1].time;	
}

int main(){

	scanf("%d %d", &X, &Y);
	int i,j;
	for(i=1; i<=Y; i++){
		for(j=1; j<=X; j++) scanf("%1d", &a[i][j]);
	}
	scanf("%d %d", &a1, &b1);
	printf("%d\n", find()+3);
	int t=0;
	for(i=1; i<=Y; i++){
		for(j=1; j<=X; j++) t+= a[i][j];
	}
	printf("%d",t);
	return 0;

}
