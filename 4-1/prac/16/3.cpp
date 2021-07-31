#include <iostream>
#include <queue>

using namespace std;

int N,M,D;

int map[16][16];
int temp[16][16];
int check[16][16];
int visit[16][16];
int ans;
int dx[]={-1,1,0};
int dy[]={0,0,-1};

int d(int y1, int x1, int y2, int x2){
	int x,y;
	if(y1 > y2) y = y1-y2;
	else y = y2 - y1;
	if(x1 > x2) x = x1-x2;
	else x = x2 - x1;
	return x+y;
}

int find(int w1, int w2, int w3){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			temp[i][j] = map[i][j];
		}
	}
	int pos = N;
	int al[3]={w1,w2,w3};
	
	while(pos >0){
		for(int i=0; i<3; i++){
			for(int j=0; j<N; j++){
				for(int k=0; k<M; k++) visit[i][j]=0;
			}
			queue<pair<int,int>> q;
			int x = al[i];
			int y = pos-1;
			q.push({y,x});
			while(!q.empty()){
				int ny = q.front().first;
				int nx = q.front().second;
				q.pop();
				visit[ny][nx]=1;
				if(temp[ny][nx]){
					check[ny][nx]=1;
					break;
				}
				for(int j=0; j<3; j++){
					int next_y = ny + dy[j];
					int next_x = nx + dx[j];
					if(next_y<0 || next_x<0 || next_x > M-1) continue;
					if(d(next_y,next_x,pos,x)<=D){
						if(visit[ny][nx]==0) q.push({next_y,next_x});
					}
				}
			}
		}
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++) if(check[i][j]) temp[i][j]=0;
		}
		pos--;
	}
	int t=0;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++) if(check[i][j]) t++;
	}
	return t;
}



int main(){
	cin >> N >> M >> D;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}
	for(int i=0; i<M; i++){
		for(int j=i+1; j<M; j++){
			for(int k=j+1; k<M; k++){
				if(find(i,j,k) > ans) ans = find(i,j,k);
			}
		}
	}
	cout << ans;
}
