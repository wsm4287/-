#include <iostream>
#include <queue>
using namespace std;

int h, w;
int map[100][100];
int ans = 0;
queue<pair<int, int>> q;

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

bool confirm(int y, int x){
	return !(map[y][x]+map[y][x+1]+map[y+1][x]+map[y+1][x+1]);
}

bool isRange(int y, int x){
	return !(y < 0 || y >= h || x < 0 || x >= w);
}

void bfs(int y, int x){
	q.push({y,x});
	map[y][x] = 1;
	
	while(!q.empty()){
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++){
			int ty = y + dy[i];
			int tx = x + dx[i];
			
			if(isRange(ty, tx)){
				if(map[ty][tx] == 0){
					q.push({ty, tx});
					map[ty][tx] = 1;
				}
			}
		}
	}
}

int main(){
	cin >> h >> w;
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cin >> map[i][j];
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
	
	cout << ans;
	
	return 0;
}