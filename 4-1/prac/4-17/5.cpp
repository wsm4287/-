#include <iostream>

using namespace std;

int n, m, x, y, K;

int map[20][20];

int a[1000];
int dice[6];

int dx[]={0,1,-1,0,0};
int dy[]={0,0,0,-1,1};

void find(){
	for(int i=0; i<K; i++){
		if(x+dx[a[i]] <0 || y+dy[a[i]] < 0 || x+dx[a[i]] >= m || y+dy[a[i]] >=n) continue;
		x += dx[a[i]];
		y += dy[a[i]];
	
		if(a[i] == 1){
			int temp = dice[0];
			dice[0] = dice[3];
			dice[3] = dice[5];
			dice[5] = dice[2];
			dice[2] = temp;
			if(map[y][x] == 0) map[y][x] = dice[5];
			else{
				dice[5] = map[y][x];
				map[y][x] = 0;
			}
		}

		if(a[i] == 2){
			int temp = dice[3];
			dice[3] = dice[0];
			dice[0] = dice[2];
			dice[2] = dice[5];
			dice[5] = temp;
			if(map[y][x] == 0) map[y][x] = dice[5];
			else{
				dice[5] = map[y][x];
				map[y][x] = 0;
			}
		}

		if(a[i] == 3){
			int temp = dice[0];
			dice[0] = dice[4];
			dice[4] = dice[5];
			dice[5] = dice[1];
			dice[1] = temp;
			if(map[y][x] == 0) map[y][x] = dice[5];
			else{
				dice[5] = map[y][x];
				map[y][x] = 0;
			}
		}

		if(a[i] == 4){
			int temp = dice[0];
			dice[0] = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[4];
			dice[4] = temp;
			if(map[y][x] == 0) map[y][x] = dice[5];
			else{
				dice[5] = map[y][x];
				map[y][x] = 0;
			}
		}
	
		cout << dice[0] << endl;
	}
}


int main(){
	cin >> n >> m >> y >> x >> K;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> map[i][j];
	}

	for(int i=0; i<K; i++) cin >> a[i];



	find();

	return 0;
}
