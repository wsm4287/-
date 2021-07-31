#include <cstdio>
#include <queue>
#define max 100

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int maze[max][max];
int a,b;

void find(int x,int y)
{
	int i;
	int nx,ny;
	queue<int> qx;
	queue<int> qy;
	qx.push(x);
	qy.push(y);
	while(!qx.empty()){
		x = qx.front();
		y = qy.front();
		qx.pop();
		qy.pop();
		for(i=0; i<4; i++){
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=0&&nx<a&&ny>=0&&ny<b){
				if(maze[nx][ny] ==1){
					maze[nx][ny]= maze[nx][ny] +maze[x][y];
					qx.push(nx);
					qy.push(ny);
					}
				}
			}
		}
}

int main()
{

	scanf("%d %d", &a, &b);
	int i,j;
	for(i=0; i<a; i++){
		for(j=0; j<b; j++)
			scanf("%d", &maze[i][j]);
		}
	find(0,0);
	printf("%d", maze[a-1][b-1]);







}
