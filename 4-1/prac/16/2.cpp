#include <iostream>

using namespace std;

int N;
int map[17][17];
int ans;

int d(int y1, int x1, int y2, int x2){
	int x = x2 - x1;
	int y = y2 - y1;
	if(x == 1 && y == 1) return 3;
	else if(x == 1) return 1;
	else if(y == 1) return 2;

}

void find(int y1, int x1, int y2, int x2){
	if(y2 == N-1 && x2 == N-1){
		ans++;
		return;
	}
	if(y2 > N-1) return;
	if(x2 > N-1) return;
	if(d(y1,x1,y2,x2)==1){
		if(map[y2][x2+1]==0) find(y2,x2,y2,x2+1);
		if(map[y2][x2+1]==0 && map[y2+1][x2]==0 && map[y2+1][x2+1]==0) find(y2,x2,y2+1,x2+1);
	}
	if(d(y1,x1,y2,x2)==2){
		if(map[y2+1][x2]==0) find(y2,x2,y2+1,x2);
		if(map[y2][x2+1]==0 && map[y2+1][x2]==0 && map[y2+1][x2+1]==0) find(y2,x2,y2+1,x2+1);
	}
	if(d(y1,x1,y2,x2)==3){
		if(map[y2+1][x2]==0) find(y2,x2,y2+1,x2);
		if(map[y2][x2+1]==0) find(y2,x2,y2,x2+1);
		if(map[y2][x2+1]==0 && map[y2+1][x2]==0 && map[y2+1][x2+1]==0) find(y2,x2,y2+1,x2+1);
	}
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) cin >> map[i][j];
	}
	find(0,0,0,1);
	cout << ans;
	return 0;
}
