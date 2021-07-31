#include <stdio.h>

int N;
int a[20][20];
int min=999999;
int check[20];
void dfs(int k, int m, int sum){
	if(k==N-1){
		if(a[m][0] == 0) return;
		if(min > sum +a[m][0]) min = sum + a[m][0];
		return;
	}
	if(sum > min) return;
	for(int i=1; i<N; i++){
		if(a[k][i] ==0 || check[i]) continue;
		check[i] =1;
		dfs(k+1, i, sum + a[m][i]);
		check[i]=0;
	}
	return;

}


int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++) scanf("%d", &a[i][j]);
	}
	dfs(0,0,0);
	printf("%d", min);
	return 0;
}
