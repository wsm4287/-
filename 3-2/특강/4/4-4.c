#include <stdio.h>

int a[20][20];
int n;
int sum;

int check(int y, int x){
	int i,j;
	for(i=0; i<y; i++) if(a[i][x] == 1) return 0;
	for(i=y-1, j=x+1; i>=0 && j<n; i--, j++) if(a[i][j] == 1) return 0;
	for(i=y-1, j=x-1; i>=0 && j>=0; i--, j--) if(a[i][j] == 1) return 0;
	return 1;
}

void dfs(int k){
	if(k==n){
		sum+=1;
		return;
	}
	for(int i=0; i<n; i++){
		if(check(k,i) == 1){
			a[k][i]=1;
			dfs(k+1);
			a[k][i]=0;
		}
	}

}

int main(){

	scanf("%d", &n);
	dfs(0);
	printf("%d", sum);
	return 0;
}
