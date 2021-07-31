#include <stdio.h>

int T, N, M;

int num[30];
int b[15];
int cnt;


void dfs(int n, int start){

	if(n==M){
		cnt++;
		return;
	}
	for(int i=start; i<30; i++){
		if(num[i]){
			num[i]--;
			b[n] = i;
			dfs(n+1, i);
			num[i]++;
		}

	}


}



int main(){
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d", &N, &M);
		int c;
		for(int j=0; j<N; j++){
			scanf("%d", &c);
			num[c]++;
		}
		dfs(0,1);
		printf("%d", cnt);
		cnt = 0;
		for(int j=0; j<30; j++) num[j]=0;
	}

	return 0;
}
