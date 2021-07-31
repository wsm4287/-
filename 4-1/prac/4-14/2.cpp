#include <iostream>

using namespace std;

int N;
int map[20][20];
int ans;

void find(int y1, int x1, int d){
	
	if(y1 == N-1 && x1 == N-1){
		ans++;
		return;
	}
	
	if(y1 > N-1 || x1 > N-1) return;

	if(d == 0){
		if(map[y1][x1+1]==0)
			find(y1, x1+1, 0);
		if(map[y1][x1+1] + map[y1+1][x1] + map[y1+1][x1+1] == 0)
			find(y1+1, x1+1, 2);
	}
	else if(d == 1){
		if(map[y1+1][x1]==0)
			find(y1+1, x1, 1);
		if(map[y1][x1+1] + map[y1+1][x1] + map[y1+1][x1+1] == 0)
			find(y1+1, x1+1, 2);

	}
	else{
		if(map[y1][x1+1]==0)
			find(y1, x1+1, 0);	
		if(map[y1+1][x1]==0)
			find(y1+1, x1, 1);
		if(map[y1][x1+1] + map[y1+1][x1] + map[y1+1][x1+1] == 0)
			find(y1+1, x1+1, 2);
	}


}


int main(){
	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) cin >> map[i][j];
	}
	find(0,1,0);
	cout << ans;
	return 0;
}
