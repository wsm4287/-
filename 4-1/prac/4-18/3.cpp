#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int map[8][8];
int ans;
int temp[8][8];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
vector<pair<int,int>> virus;
vector<pair<int,int>> em;

void run(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	while(!q.empty()){
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int ny = yy + dy[i];
			int nx = xx + dx[i];
			if(ny <0 || nx < 0 || ny >=n || nx >=m) continue;
			if(temp[ny][nx]) continue;
			temp[ny][nx] = 2;
			q.push({ny,nx});
		}
	}

}

void find(int k, int z, vector<pair<int,int>> wall){
	if(z == em.size() && k<3) return;
	if(k==3){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				temp[i][j] = map[i][j];
			}
		}
		for(int i=0; i<3; i++){
			temp[wall[i].first][wall[i].second] = 1;
		}
		for(int i=0; i<virus.size(); i++){
			run(virus[i].first, virus[i].second);
		}
		int sum = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(temp[i][j] == 0) sum++;
			}
		}
		if(sum > ans) ans = sum;
		return;
	}

	wall.push_back(em[z]);
	find(k+1, z+1, wall);
	wall.pop_back();
	find(k,z+1,wall);

}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> map[i][j];
			if(map[i][j] == 2) virus.push_back({i,j});
			if(map[i][j] == 0) em.push_back({i,j});
		}
	}
	vector<pair<int,int>> wall;
	find(0,0,wall);


	cout << ans;
	return 0;
}
