#include <iostream>

using namespace std;

int T, N, M;
int map[22][22];
int ans=0;
int visit[22][22];

int cost(int n){
	return (n*n+(n-1)*(n-1));
}

int check(int y,int x, int k){
	int t=0;
	int q = k-1;
	while(q>=0){
		int i1=y-q; 
		int i2=y+q;
		for(int j=x-(k-1)+q; j<=x+(k-1)-q; j++){
			if(i1 <0 || j<0 || i1>=N || j>=N) continue;
			if(visit[i1][j]) continue;
			if(map[i1][j]==1){
				t++;
				visit[i1][j]=1;
			}
		}
		for(int j=x-(k-1)+q; j<=x+(k-1)-q; j++){
			if(i2 <0 || j<0 || i2>=N || j>=N) continue;
			if(visit[i2][j]) continue;
			if(map[i2][j]==1){
				t++;
				visit[i2][j]=1;
			}
		}
	
	q--;
	}
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			visit[i][j]=0;
		}
	}

	if(t*M-cost(k)>=0)
		return t;
	else
		return 0;

}

void find(int k){
	int max=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(check(i,j,k)> max) max = check(i,j,k);
		}
	}
	if(max > ans) ans = max;
}


int main(){
	cin >> T;
	for(int t=1; t<=T; t++){
		cin >> N >> M;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++) cin >> map[i][j];
		}
		for(int i=0; i<=N+1; i++)
			find(i);
		cout << "#" << t << " " << ans << endl;
		ans = 0;
	}
	return 0;
}
