#include <iostream>
#include <queue>

using namespace std;

int T, N, M, K;

int map[350][350];
int live[350][350][2]; // [0]에는 life만큼(비어있은지 구분) [1]은 활성화/비활성화 구분 
int ans;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void find(int k){

	while(K>k){
		queue <pair<int,int>> active;
		for(int i=1; i<350; i++){
			for(int j=1; j<350; j++){
				if(live[i][j][1] >0 && live[i][j][1] <= live[i][j][0]){  // 활성화 상태
					active.push({i,j});
					live[i][j][1]--;
				}
				else if(live[i][j][1] > live[i][j][0]) live[i][j][1]--;  // 비활성화 상태
			}
		}

		while(!active.empty()){
			int ny = active.front().first;
			int nx = active.front().second;
			active.pop();
			for(int t=0; t<4; t++){
				int yy = ny + dy[t];
				int xx = nx + dx[t];
				if(yy <0 || nx <0 || ny >= 350 || nx >= 350) continue;
				if(map[yy][xx] == 0){
					map[yy][xx] = map[ny][nx];
					live[yy][xx][0] = map[ny][nx];
					live[yy][xx][1] = 2*map[ny][nx];
				}
				else if(live[yy][xx][1] == 2 * live[yy][xx][0]){
						if(map[ny][nx] > live[yy][xx][0]){
							map[yy][xx] = map[ny][nx];
							live[yy][xx][0] = map[ny][nx];
							live[yy][xx][1] = 2*map[ny][nx];
						}
				}

			}



		}
	k++;
	}


}

int main(){
	cin >> T;
	for(int k=1; k<=T; k++){
		cin >> N >> M >> K;
		for(int i=150; i<150+N; i++){
			for(int j=150; j<150+M; j++){
				cin >> map[i][j];
				if(map[i][j]){
					live[i][j][0] = map[i][j];
					live[i][j][1] = 2*map[i][j];
				}
			}
		}
		find(0);
		for(int i=0; i<350; i++){
			for(int j=0; j<350; j++){
				if(live[i][j][1]) ans++;
			}
		}
	
		cout << "#" << k << " " << ans << endl;
		ans = 0;
		for(int i=0; i<350; i++){
			for(int j=0; j<350; j++){
				map[i][j] = 0;
				live[i][j][0] = 0;
				live[i][j][1] = 0;
			}
		}


	}
	return 0;
}
