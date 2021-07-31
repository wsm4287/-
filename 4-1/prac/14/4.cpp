#include <iostream>
#include <queue>

using namespace std;

int T,N,M;
char map[10][10];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ans=-1;

struct ball{
	int depth;
	int x1,y1,x2,y2;
};
int visit[10][10][10][10];


void find(int k,int x1,int y1, int x2, int y2){
	queue<ball> q;
	q.push({k,x1,y1,x2,y2});
	visit[y1][x1][y2][x2]=1;
	
	while(!q.empty()){
		ball cur = q.front();
		q.pop();
		
		if(cur.depth>10) break;
		if(map[cur.y1][cur.x1]=='O'){
			ans = cur.depth;
			return;
		}

		for(int i=0; i<4; i++){
			int nx1 = cur.x1;
			int ny1 = cur.y1;
			int nx2 = cur.x2;
			int ny2 = cur.y2;
			while(1){
				nx1 += dx[i];
				ny1 += dy[i];
				if(map[ny1][nx1] == '#'){
						nx1 -=dx[i];
						ny1 -=dy[i];
						break;
				}
				else if(map[ny1][nx1] == 'O') break;
			}

			while(1){
				nx2 += dx[i];
				ny2 += dy[i];
				if(map[ny2][nx2] == '#'){
						nx2 -=dx[i];
						ny2 -=dy[i];
						break;
				}
				else if(map[ny2][nx2] == 'O') break;
			}
		
			if(map[ny2][nx2] == 'O') continue;

			if(nx1 == nx2 && ny1 == ny2){
				if(i==0){
					if(cur.x1 > cur.x2) nx1++;
					else nx2++;
				}
				if(i==1){
					if(cur.x1 > cur.x2) nx2--;
					else nx1--;
				}
				if(i==2){
					if(cur.y1 > cur.y2) ny1++;
					else ny2++;
				}
				if(i==3){
					if(cur.y1 > cur.y2) ny2--;
					else ny1--;
				}
			}

			if(!visit[ny1][nx1][ny2][nx2]){ 
				ball next = {cur.depth+1,nx1,ny1,nx2,ny2};
				q.push(next);
				visit[ny1][nx1][ny2][nx2]=1;
			}
		}
	}
}

int main(){
	cin >> N >> M;
	int x1,y1,x2,y2;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
			if(map[i][j]=='R'){
				x1=j;
				y1=i;
			}
			else if(map[i][j]=='B'){
				x2=j;
				y2=i;
			}
		}
	}
	find(0,x1,y1,x2,y2);
	cout << ans << endl;
	return 0;
}
