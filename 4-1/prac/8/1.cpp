#include <iostream>
#include <queue>

using namespace std;

int T, N, M, R, C, L;

int map[55][55];
int ans=0;
int visit[55][55];

int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

void find(int y, int x, int k){
	queue<pair<pair<int, int>, int>> qq;
	qq.push({{y,x},k});
	while(!qq.empty()){
		int ny = qq.front().first.first;
		int nx = qq.front().first.second;
		int time = qq.front().second;
		qq.pop();
		if(time == L) continue;
		for(int i=0; i<4; i++){
			int x1 = nx + dx[i];
			int y1 = ny + dy[i];
			if(x1 <0 || y1 < 0 || x1 >=M || y1 >= N) continue;
			if(map[y1][x1] == 0) continue;
			if(visit[y1][x1]) continue;
			if(map[ny][nx] == 2 && (i==2||i==3)) continue;
			if(map[ny][nx] == 3 && (i==0||i==1)) continue;
			if(map[ny][nx] == 4 && (i==1||i==2)) continue;
			if(map[ny][nx] == 5 && (i==0||i==2)) continue;
			if(map[ny][nx] == 6 && (i==0||i==3)) continue;
			if(map[ny][nx] == 7 && (i==1||i==3)) continue;

			if(i==0){
				if(map[y1][x1] == 3 || map[y1][x1] == 4 || map[y1][x1] == 7) continue;
				visit[y1][x1] = 1;
				qq.push({{y1,x1},time+1});
			}
			if(i==0){
				if(map[y1][x1] == 3 || map[y1][x1] == 4 || map[y1][x1] == 7) continue;
				visit[y1][x1] = 1;
				qq.push({{y1,x1},time+1});
			}
			if(i==1){
				if(map[y1][x1] == 3 || map[y1][x1] == 5 || map[y1][x1] == 6) continue;
				visit[y1][x1] = 1;
				qq.push({{y1,x1},time+1});
			}
			if(i==2){
				if(map[y1][x1] == 2 || map[y1][x1] == 6 || map[y1][x1] == 7) continue;
				visit[y1][x1] = 1;
				qq.push({{y1,x1},time+1});
			}
			if(i==3){
				if(map[y1][x1] == 2 || map[y1][x1] == 4 || map[y1][x1] == 5) continue;
				visit[y1][x1] = 1;
				qq.push({{y1,x1},time+1});
			}
		}

	}

}
int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N >> M >> R >> C >> L;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				cin >> map[i][j];
			}
		}
		visit[R][C] = 1;
		find(R,C,1);

		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				if(visit[i][j]) ans++;
			}
		}
		cout << "#" << t << " " << ans << endl;
		ans = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++){
				visit[i][j] = 0;
			}
		}
	}
}
