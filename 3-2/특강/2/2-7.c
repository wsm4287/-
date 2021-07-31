#include <stdio.h>

int X, Y;
int a[1010][1010];
typedef struct _que{
	int x, y, time;
}QUE;
QUE que[1000000];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int rp, wp;
int zero;

int find(){
	QUE q;
	while(rp <wp){
		q = que[rp++];
		for(int i=0; i<4; i++){
			int nx = q.x+dx[i];
			int ny = q.y+dy[i];
			if(nx <1 || nx > X || ny < 1 || ny > Y) continue;
			if(a[ny][nx] == 0){
				que[wp].x = nx;
				que[wp].y = ny;
				que[wp++].time = q.time+1;
				a[ny][nx] = 1;
				zero--;
			}
		}
	}
	return q.time;	
}


int main(){
	scanf("%d %d", &X, &Y);
	int i,j;
	for(i=1; i<=Y; i++){
		for(j=1; j<=X; j++){ 
			scanf("%d", &a[i][j]);
			if(a[i][j] == 1){
				que[wp].x = j;
				que[wp].y = i;
				que[wp++].time = 0;
			}
			else if(a[i][j] == 0) zero++;
		}

	}
	int p =find();
	if(zero != 0){ 
		printf("%d", -1);
		return 0;
	}
	printf("%d\n", p);
	return 0;

}