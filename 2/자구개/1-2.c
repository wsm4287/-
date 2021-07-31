#include <stdio.h>

int h, w;
int map[100][100];
int ans = 0;
int q[100000][2];

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int confirm(int y, int x){
	return !(map[y][x]+map[y][x+1]+map[y+1][x]+map[y+1][x+1]);
}

int isRange(int y, int x){
	return !(y < 0 || y >= h || x < 0 || x >= w);
}

void bfs(int y, int x){
	int rd = 0;
	int wt = 0;
	q[wt][0] = y; q[wt++][1] = x;
	map[y][x] = 1;
	
	while(rd < wt){
		y = q[rd][0];
		x = q[rd++][1];
		
		for(int i=0; i<4; i++){
			int ty = y + dy[i];
			int tx = x + dx[i];
			
			if(isRange(ty, tx)){
				if(map[ty][tx] == 0){
					q[wt][0] = ty; q[wt++][1] = tx;
					map[ty][tx] = 1;
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &h, &w);
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			scanf("%d", &map[i][j]);
		}
	}
	
	for(int i=0; i<h-1; i++){
		for(int j=0; j<w-1; j++){
			if(map[i][j] == 0){
				if(confirm(i, j)){ // map[i][j]에서 고양이가 들어갈수 있다면?
					bfs(i, j);// 연결된 0을 모두 체크한다
					ans++;
				} 
			}
		}
	}
	
	printf("%d", ans);
	
	return 0;
}