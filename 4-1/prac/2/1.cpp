#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, N, W, H;
int ans = 99999999;

int a[20][15];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void cop(int b[20][15], int b1[20][15]){
	for(int i=1; i<= H; i++){
		for(int j=1; j<= W; j++)
			b1[i][j] = b[i][j];
	}
}

void bsort(){
	for(int j=1; j<= W; j++){
		queue<int> qq;
		for(int i=H; i>0; i--){
			if(a[i][j]){
				qq.push(a[i][j]);
				a[i][j]=0;
			}
		}
		int t = H;
		while(!qq.empty()){
			a[t][j] = qq.front();
			qq.pop();
			t--;
		}
	}


}


void drop(int i, int j, int size){
	if(size == 0){
		if(i+1 > H) return;
		drop(i+1, j, a[i+1][j]);
	}
	else{
		queue<pair<pair<int,int>,int>> que;
		que.push({{i,j},size});
		a[i][j] = 0;
		while(!que.empty()){
			int y = que.front().first.first;
			int x = que.front().first.second;
			int s = que.front().second;
			que.pop();
			a[y][x] = 0;
			for(int i=1; i< s; i++){
				for(int k=0; k<4; k++){
					int ny = y + i*dy[k];
					int nx = x + i*dx[k];
					if(nx<1 || ny<1 || nx > W || ny > H) continue;
					if(a[ny][nx]){
						que.push({{ny,nx},a[ny][nx]});
						a[ny][nx]=0;
					}
				}
			}
	
		}

		bsort();
	}

}


void find(int k){
	if(k >= N){
		int sum=0;
		for(int i=1; i<=H; i++){
			for(int j=1; j<=W; j++){
				if(a[i][j]) sum++;
			}
		}
		if(ans > sum) ans = sum;
		return;
	}
	
	int a1[20][15];
	for(int j=1; j<=W; j++){
		cop(a, a1);
		drop(0,j,0);
		find(k+1);
		cop(a1,a);
	}
}

int main(){

	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> N >> W >> H;
		for(int j=1; j<=H; j++){
			for(int k=1; k<=W; k++)
				cin >> a[j][k];
		}

		find(0);
		cout << "#" << i << " " << ans << endl;
		ans = 9999999;
		for(int j=1; j<=H; j++){
			for(int k=1; k<=W; k++) a[j][k] = 0;
		}
	}




}
