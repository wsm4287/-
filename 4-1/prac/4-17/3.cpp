#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,k,l;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int ans;
queue <pair<int,int>> ro;
vector <pair<int,int>> body;

int map[100][100];

void find(int y, int x, int k, int d){
	
	int nd = d;
	if(k == ro.front().first){
		if(d == 0){
			if(ro.front().second == 1) nd = 2;
			else nd = 3;
		}
		if(d == 1){
			if(ro.front().second == 1) nd = 3;
			else nd = 2;
		}
		if(d == 2){
			if(ro.front().second == 1) nd = 1;
			else nd = 0;
		}
		if(d == 3){
			if(ro.front().second == 1) nd = 0;
			else nd = 1;
		}
		ro.pop();
	}

	int ny = y + dy[nd];
	int nx = x + dx[nd];

	if(ny < 0 || nx < 0 || ny >n-1 ||nx > n-1){
		ans = k+1;
		return;
	}
	//cout << endl << k << endl;
	for(int i=0; i<body.size(); i++){
		//cout << body[i].first << " " << body[i].second << endl;
		if(ny == body[i].first && nx == body[i].second){
			ans = k+1;
			return;
		}
	}

	
	body.push_back({y,x});

	if(map[ny][nx] == 0){
		for(int i=0; i<body.size(); i++){
			body[i] = body[i+1];
		}
		body.pop_back();
	}
	map[ny][nx] = 0;
	//cout << k << " " << ny << " " << nx << " " << nd << endl;
	find(ny,nx,k+1,nd);


}

int main(){
	cin >> n;
	cin >> k;
	int x,y;
	for(int i=0; i<k; i++){
		cin >> y >> x;
		map[y-1][x-1] = 1;
	}
	cin >> l;
	int a;
	char b;
	for(int i=0; i<l; i++){
		cin >> a >> b;
		if(b == 'D') ro.push({a,-1});
		if(b == 'L') ro.push({a,1});
	}
	find(0,0,0,3);
	cout << ans;
}
