#include <iostream>
#include <vector>

using namespace std;

int n,m;
int map[500][500];
int ans;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

void find(int y, int x, int k, int sum, vector <pair<int,int>> v){
	if(k==4){
		if(sum > ans) ans = sum;
		return;
	}

	v.push_back({y,x});
	sum += map[y][x];
	if(k==3){
		if(ans > sum) return;
	}
	for(int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		int c = 0;
		if(ny <0 || nx <0 || ny >=n || nx >=m) continue;
		for(int j=0; j<v.size(); j++){
			if(ny == v[j].first && nx == v[j].second){
				c = 1;
				break;
			}
		}
		if(c) continue;
		find(ny,nx,k+1,sum,v);
	}

}

void re(int y, int x, int k, int sum, vector<int> v){
	
	if(k == 3){
		if(sum > ans) ans = sum;
		return;
	}
	for(int i=0; i<4; i++){
		int c = 0;
		for(int j=0; j<v.size(); j++){
			if(i == v[j]){
				c = 1;
				break;
			}
		}
		if(c) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny <0 || nx <0 || ny >=n || nx >=m) continue;
		v.push_back(i);
		re(y,x,k+1,sum+map[ny][nx],v);
		v.pop_back();
	}

}

int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			vector <pair<int,int>> v;
			find(i,j,0,0,v);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			vector <int> v;
			re(i,j,0,map[i][j],v);
		}
	}

	cout << ans;

}
