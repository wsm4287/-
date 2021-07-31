#include <iostream>

using namespace std;

int T,D,W,K;

int map[15][22];
int temp[15][22];
int ans=9999999;
int list[15];

int chec(){
	int max[W];
	for(int i=0; i<W; i++) max[i] = 0;
	for(int j=0; j<W; j++){
		int x = 1;
		for(int i=0; i<D-1; i++){
			if(map[i][j] == map[i+1][j]){
				x++;
				if(x > max[j]) max[j] = x;
			}
			else{
				if(x > max[j]) max[j] = x;
				x = 1;
			}
		}
		if(max[j] < K) return 0;
	}
	return 1;
}

void find(int f, int k){
	if(ans < k) return;
	if(chec()){
		if(ans > k) ans = k;
		return;
	}
	if(f >= D) return;
	find(f+1,k);
	
	for(int i=0; i<W; i++)
		map[f][i] = 0;
	find(f+1,k+1);

	for(int i=0; i<W; i++)
		map[f][i] = 1;
	find(f+1,k+1);

	for(int i=0; i<W; i++)
		map[f][i] = temp[f][i];

	
}

int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> D >> W >> K;
		for(int i=0; i<D; i++){
			for(int j=0; j<W; j++){
				cin >> map[i][j];
				temp[i][j] = map[i][j];
			}
		}
		find(0,0);
		cout << "#" << t << " " << ans << endl;
		ans = 9999999;
	}
	return 0;

}
