#include <iostream>

using namespace std;

int n,m,h;
int map[31][12];

int ans=9;

int go(int x){
	int xx = x;
	int yy = 1;

	for(int i=yy; i<=h; i++){
		if(map[i][xx] == 1){
			xx++;
		}
		else if(map[i][xx-1] == 1) xx--;
	}
	if(xx == x) return 1;
	return 0;
}

void find(int k, int id){
	if(k>ans) return;
	int c = 1;
	for(int i=1; i<=n; i++){
		if(go(i)==0){
			c = 0;
			break;
		}
	}
	if(c==1){
		if(ans > k) ans = k;
		return;
	}

	if(k>=3) return;

	for(int i=id; i<=h; i++){
		for(int j=1; j<=n; j++){
			if(!map[i][j] && !map[i][j-1] && !map[i][j+1]){
				map[i][j] = 1;
				find(k+1,i);
				map[i][j] = 0;
			} 
		}
	}
}

int main(){
	cin >> n >> m >> h;
	int a,b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		map[a][b] = 1;
	}

	find(0,1);

	if(ans>3) ans = -1;
	cout << ans;
	return 0;
}
