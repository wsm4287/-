#include <iostream>

using namespace std;


int ans=9999;

int paper[5];

int check(int map[10][10], int y, int x, int k){
	if(y+k>10 || x+k>10) return 0;
	for(int i=y; i<y+k; i++){
		for(int j=x; j<x+k; j++){
			if(map[i][j]==0) return 0;
		}
	}
	return 1;
}


void find(int map[10][10], int sum){

	if(sum > ans) return;

	int yy;
	int xx;
	int c=0;
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			if(map[i][j]){
				yy=i;
				xx=j;
				i=10;
				j=10;
				c=1;
			}
		}
	}
	if(!c){
		if(sum < ans){
			ans = sum;
		}
		return;
	}

	for(int k=4; k>=0; k--){
		if(paper[k]>4) continue;
		if(check(map,yy,xx,k+1)==0) continue;
		int newMap[10][10];
		for(int i=0; i<10; i++){
			for(int j=0; j<10; j++) newMap[i][j] = map[i][j];
		}
		for(int i=yy; i<=yy+k; i++){
			for(int j=xx; j<=xx+k; j++) newMap[i][j] = 0;
		}
		paper[k]++;
		find(newMap,sum+1);
		paper[k]--;
	}

}

int main() {
	int map[10][10];
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
		}
	}
	find(map,0);
	if(ans==9999) ans=-1;
	cout << ans;
	return 0;
}
