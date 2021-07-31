#include <cstdio>
#include <queue>
using namespace std;

int N, M;
int maze[105][105];
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

void findMaze(int x, int y){
	queue<int> q_x;
	queue<int> q_y;
	q_x.push(x);
	q_y.push(y);
	while(!q_x.empty()){
		x = q_x.front();
		y = q_y.front();
		q_x.pop();
		q_y.pop();
		for(int k = 0 ; k < 4; k++){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;
			if(maze[nx][ny] == 1){
				q_x.push(nx);
				q_y.push(ny);
				maze[nx][ny]=maze[x][y]+1;
			}
		}
	}
}

int main() {
	scanf("%d %d",&N,&M);
	for(int i = 0 ; i <N ; i++){
		for(int j = 0 ; j < M ; j++){
			scanf("%d",&maze[i][j]);
		}
	}
    findMaze(2,4);

    for(int i = 0 ; i <N ; i++){
		for(int j = 0 ; j < M ; j++){
			printf("%2d ",maze[i][j]);
		}
		printf("\n");
	}

	printf("%d\n",maze[N-1][M-1]);

	return 0;
}

