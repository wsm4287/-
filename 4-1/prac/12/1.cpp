#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, N;
int ans = 99999999;

int map[11][11];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};


vector<pair<int,int>> people;
vector<pair<int,int>> stair;

int s[10];
int d[10];

int dist(int x1, int x2, int y1, int y2){
	int x = 0;
	if(x1 > x2) x = x1-x2;
	else x = x2 - x1;
	int y = 0;
	if(y1 > y2) y = y1-y2;
	else y = y2 - y1;
	return x+y;
}

int calc(){

	int t = 0;
	int check = 0;
	queue<int> wait[2];
	for(int i=0; i<people.size(); i++){
		d[i] = dist(people[i].first, stair[s[i]].first,people[i].second, stair[s[i]].second);
	}

	while(1){
		if(t >= ans) return t;
		if(check == people.size()) return t;

		for(int i=0; i<2; i++){
			int ss = wait[i].size();
			cout << ss << endl;
			for(int j=0; j< ss; ++j){
				int top = wait[i].front();
				wait[i].pop();
				top--;
				if(top == 0) check++;
				else wait[i].push(top);
			}
		}

		for(int i=0; i<people.size(); i++){
			if(d[i] == 0){
				if(wait[s[i]].size() < 3) wait[s[i]].push(map[stair[s[i]].first][stair[s[i]].second]);
				else wait[s[i]].push(map[stair[s[i]].first][stair[s[i]].second] + wait[s[i]].front());
			}
			d[i]--;
		}
		t++;
	}

}

void find(int k){
	if(k == people.size()){
		int X = calc();
		if(ans > X) ans = X;
		return;
	}

	s[k] = 0;
	find(k+1);
	s[k] = 1;
	find(k+1);

}

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				cin >> map[i][j];
				if(map[i][j]==1){
					people.push_back({i,j});
				}
				else if(map[i][j]>1){
					stair.push_back({i,j});
				}
			}
		}

		find(0);
		cout << "#" << t << " " << ans << endl;
		ans = 99999999;
		for(int i=0; i<people.size(); i++){
			s[i]=0;
			d[i]=0;
		}
		people.clear();
		stair.clear();
	}

	return 0;
}
