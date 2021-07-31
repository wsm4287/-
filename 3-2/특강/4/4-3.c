#include <stdio.h>

int a[20][20];
int n;
int cost;
int check[20];
int min;

void dfs(int k,int sum){
	if(sum > min) return;
	if(k>n){
		if(min > sum) min=sum;
		return;
	}
	for(int i=1; i<=n; i++){
		if(check[i] == 1) continue;
		check[i] = 1;
		dfs(k+1, sum + a[k][i]);
		check[i] = 0;
	}


}


int main(){

	scanf("%d", &n);
	int i,j;
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	min = 9999999;
	dfs(1,0);
	printf("%d", min);
	return 0;
}
