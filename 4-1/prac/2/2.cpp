#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, W, H;

int a[20][15];
int a1[20][15];

int ans = 99999;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void backup(){
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			a[i][j] = a1[i][j];
			a1[i][j] = 0;
		}
	}
}

void bsort(){

	for(int q=0; q<W; q++){
		queue<int> que;
		for(int p=H-1; p>=0; p--){
			if(a[p][q]){
				que.push(a[p][q]);
				a[p][q] = 0;
			}
			
		}
		int t = que.size();
		while(!que.empty()){
			a[t-1][q] = que.front();
			que.pop();
			t--;
		}
	}


}

void drop(int i, int j){
	if(a[i][j] == 0){
		if(i > H) return;
		drop(i+1, j);
	}
	else{
		queue<pair<pair<int,int>,int>> qq;
		qq.push({{i,j},a[i][j]});
		a[i][j] = 0;
		while(!qq.empty()){
			int y = qq.front().first.first;
			int x = qq.front().first.second;
			int d = qq.front().second;
			qq.pop();
			a[y][x]=0;
			for(int t=0; t<d; t++){
				for(int k=0; k<4; k++){
					int nx = x + t*dx[k];
					int ny = y + t*dy[k];
					if(nx<0||ny<0||nx>W-1||ny>H-1) continue;
					if(a[ny][nx]){
						qq.push({{ny,nx},d});
						a[ny][nx]=0;
					}
				}
			}
		}
		bsort();
	}

}


void erase(int i, int j){
	for(int q=0; q<H; q++){
		for(int p=0; p<W; p++){
			a1[q][p] = a[q][p];
		}
	}

	drop(i,j);

}


void find(int k){
	//if(X > ans) return;

	if(k >= N){
		int X=0;
		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				if(a[i][j]) X++;
			}
		}
	if(ans > X) ans = X;
		return;
	}

	for(int j=0; j<W; j++){
		erase(0,j);
		find(k+1);
		backup();
	}


}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
	  cin >> N >> W >> H;
	  for(int i=0; i<H; i++){
		  for(int j=0; j<W; j++){
			  cin >> a[i][j];
		  }
	  }
		find(0);
	
		cout << "#" << test_case << " " << ans << endl;

		for(int i=0; i<H; i++){
			for(int j=0; j<W; j++){
				a[i][j] = 0;
			}
		}
		ans = 99999;

	}
	return 0;
}
