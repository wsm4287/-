#include <iostream>
#include <vector>

using namespace std;

int n;
int map[101][101];

int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int ans;

vector <pair<pair<int,int>,pair<int,int>>> v;


void go(vector<pair<int,int>> dragon, int g, int k){
	if(k==g){
		for(int i=0; i<dragon.size(); i++){
			map[dragon[i].first][dragon[i].second] = 1;
		}
		return;
	}

	int s = dragon.size()-1;
	int xx = dragon[s].first;
	int yy = dragon[s].second;

	for(int i=s-1; i>=0; i--){
		int nx = xx - dragon[i].first;
		int ny = yy - dragon[i].second;
		if(xx+ny <0 || yy-nx<0 || xx+ny>100 || yy-nx>100) continue;
		dragon.push_back({xx+ny,yy-nx});
	}
	go(dragon,g,k+1);
}

void run(int t){	
	int x = v[t].first.first;
	int y = v[t].first.second;
	int d = v[t].second.first;
	int g = v[t].second.second;

	vector<pair<int,int>> dragon;
	dragon.push_back({x,y});
	dragon.push_back({x+dx[d],y+dy[d]});
	go(dragon,g,0);
}

int main(){
	cin >> n;
	int x,y,d,g;
	for(int i=0; i<n; i++){
		cin >> x >> y >> d >> g;
		v.push_back({{x,y},{d,g}});
	}
	for(int i=0; i<n; i++) run(i);

	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
