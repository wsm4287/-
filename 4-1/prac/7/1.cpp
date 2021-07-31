#include <iostream>

using namespace std;

int T, N, K;

int map[9][9];
int visit[9][9];
int ans = 0;
int mx = 0;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void check(int mx, int y, int x, int k, int c){
	if(k> ans) ans = k;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx <0 || ny < 0 || nx >=N || ny >= N) continue;
		if(visit[ny][nx]==0){
			if(map[ny][nx] < mx){
				visit[ny][nx] = 1;
				check(map[ny][nx],ny,nx,k+1,c);
				visit[ny][nx] = 0;
			}
			else{
				if(c == 0){
					for(int j=1; j<=K; j++){
						if(map[ny][nx] - j < mx){
							visit[ny][nx] = 1;
							check(map[ny][nx]-j,ny,nx,k+1,1);
							visit[ny][nx] = 0;
						}
					}
				}
			}

		}
	}

}

int main(){

	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N >> K;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> map[i][j];
				if(map[i][j] > mx) mx = map[i][j];
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(map[i][j] == mx){
					visit[i][j] = 1;
					check(mx, i, j, 1, 0);
					visit[i][j] = 0;
				}
			}
		}
		cout << "#" << t << " " << ans << endl;
		mx = 0;
		ans = 0;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++) visit[i][j] = 0;
		}
	}
	return 0;
}
