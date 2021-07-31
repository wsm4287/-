#include <stdio.h>

typedef struct {
	int x, y;
}POS;

POS ck[20], hs[400];

POS que[10000];

int wp, rp;

int N, M;
int a[30][30];
int min = 999999;
int chk[30];
int ct, ht;

int mn(int i, int j){
	if(i >j) return i-j;
	return j-i;
}

int bfs(int y, int x){
	que[wp++] = (QUE){x, y};
	while(rp < wp){
		QUE q = que[rp++];
		for(int i=0; i<4; i++){
			int nx = x + dj[i];
			int ny = y + di[i];
			if(nx <0 || ny <0 || nx >N-1 || ny > N-1) continue;
			que[wp++] = (QUE){x, y};
			if(a[ny][nx] == 2){
				rp = 0;
				wp = 0;
				return mn(y,ny)+mn(x,nx);
			}
		}
	}


}

void dfs(int k){
		
	if(k == M){
		int lengthi = 0;
		for(int i=0; i<N; i++){	
			for(int j=0; j<N; j++){
				if(a[i][j] == 1) length += bfs(i,j);
			}
		}
		if(min > length) min = length;
		return;
	}
	for(int i=0; i<M; i++){
		if(chk[i]) continue;
		chk[i] = 1;
		dfs(k+1);
		chk[i] = 0;
	}

}


int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &a[i][j]);
			if(a[i][j] == 2) ch[ct++] = (PS) {j,i};
			if(a[i][j] == 1) hs[ht++] = (PS) {j,i};
		}
	}
	dfs(0);
	printf("%d", min);

}
