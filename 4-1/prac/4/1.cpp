#include <iostream>
#include <vector>

using namespace std;

int T, N;
int map[110][110];
int ans;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

vector<pair<int,int>> Warm[5];


int run(int y, int x, int dir){
	int sum=0;
	int yy = y + dy[dir];
	int xx = x + dx[dir];
	int d = dir;
	while(1){
		if(yy <1 || xx < 1 || yy > N || xx > N){
			sum++;
			if(d == 0) d =1;
			else if(d == 1) d = 0;
			else if(d == 2) d = 3;
			else d = 2;
			yy = yy + dy[d];
			xx = xx + dx[d];
			continue;
		}
		if(map[yy][xx] == -1 || (yy == y && xx == x)) return sum;

		if(map[yy][xx] == 0){
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else if(map[yy][xx] == 1){
			sum++;
			if(d == 0) d = 1;
			else if(d == 1) d = 3;
			else if(d == 2) d = 0;
			else d = 2;
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else if(map[yy][xx] == 2){
			sum++;
			if(d == 0) d = 3;
			else if(d == 1) d = 0;
			else if(d == 2) d = 1;
			else d = 2;
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else if(map[yy][xx] == 3){
			sum++;
			if(d == 0) d = 2;
			else if(d == 1) d = 0;
			else if(d == 2) d = 3;
			else d = 1;
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else if(map[yy][xx] == 4){
			sum++;
			if(d == 0) d = 1;
			else if(d == 1) d = 2;
			else if(d == 2) d = 3;
			else d = 0;
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else if(map[yy][xx] == 5){
			sum++;
			if(d == 0) d = 1;
			else if(d == 1) d = 0;
			else if(d == 2) d = 3;
			else d = 2;
			yy = yy + dy[d];
			xx = xx + dx[d];
		}
		else{
			int y1 = Warm[map[yy][xx]-6].front().first;
			int x1 = Warm[map[yy][xx]-6].front().second;
			if(yy == y1 && xx == x1){
				y1 = Warm[map[yy][xx]-6].back().first;
				x1 = Warm[map[yy][xx]-6].back().second;
			}
			yy = y1 + dy[d];
			xx = x1 + dx[d];
		}
	}



}


int roll(int y, int x){
	int r = run(y,x,1);
	int l = run(y,x,0);
	int u = run(y,x,3);
	int d = run(y,x,2);
	if(l > r) r = l;
	if(u > r) r = u;
	if(d > r) r = d;
	return r;


}

void find(){
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j] == 0){
				if(roll(i,j) > ans) ans = roll(i,j);
			}
		}
	}

}


int main(){

	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				cin >> map[i][j];
				if(map[i][j] >=6){
					Warm[map[i][j]-6].push_back({i,j});
				}
			}
		}

		find();

		cout << "#" << t << " " << ans << endl;
		ans = 0;
		for(int i=1; i<=N; i++){
			for(int j=1; j<=N; j++){
				map[i][j] = 0;
			}
		}
		for(int i=0; i<5; i++){
				Warm[i].clear();
		}
	}

	return 0;
}
