#include <stdio.h>



int N;
int a[110][110];
int visit[110];
int que[110];
int wp, rp;

int bfs(){
	int cnt;
	que[wp++] =1;
	visit[1] =1;
	while(rp < wp){
		int q = que[rp++];
		for(int i=1; i<= N; i++){
			if(a[q][i] == 1 && visit[i] == 0){
				que[wp++] = i;
				visit[i] = 1;
				cnt++;
			}
					
		}
		
	}
	return cnt;
}



int main(){

	scanf("%d", &N);
	int i,m;
	scanf("%d", &m);
	int x,y;
	for(i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	printf("%d", bfs());

	return 0;
}
