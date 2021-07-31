#include <iostream>
#include <queue>

using namespace std;
int n,m;
int map[55][55];
int visit[55][55];

int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};

int ans;

void find(int y,int x,int d,int k){
	if(visit[y][x] == 0){
		visit[y][x] = 1;
		ans++;
	}
	int ny,nx,nd;
	nd = (d+3)%4;
	ny = y + dy[nd];
	nx = x + dx[nd];
	if(visit[ny][nx]==0 && !map[ny][nx]) find(ny,nx,nd,0);
	else if(k<4) find(y,x,nd,k+1);
	else if(k==4){
		nd = (d+2)%4;
		ny = y + dy[nd];
		nx = x + dx[nd];
		if(map[ny][nx]) return;
		find(ny,nx,d,0);
	}
}

int main(){
	int r,c,d;
	cin >> n >>m;
	cin >> r >> c >> d;
	for(int i=0; i<=m; i++) map[n+1][i] = 1;
	for(int i=0; i<=m; i++) map[0][i] = 1;
	for(int i=0; i<=n; i++) map[i][0] = 1;
	for(int i=0; i<=n; i++) map[i][m+1] = 1;

	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++) cin >> map[i][j];
	}
	find(r+1,c+1,d,0);

	cout << ans;


	return 0;
}
