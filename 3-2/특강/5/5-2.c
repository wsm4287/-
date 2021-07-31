#include <stdio.h>

int N1, N2;
int a[15];
int b[10];

int dfs(int k, int sum, int X){
	if(k>N1) return 0;
	if(sum == X) return 1;	
	if(dfs(k+1, sum + a[k], X)) return 1;
	if(dfs(k+1, sum, X)) return 1;
	if(dfs(k+1, sum, X+a[k])) return 1;
	return 0;


}



int main(){

	scanf("%d", &N1);
	for(int i=0; i<N1; i++) scanf("%d", &a[i]);
	scanf("%d", &N2);
	for(int i=0; i<N2; i++) scanf("%d", &b[i]);
	for(int i=0; i<N2; i++){
		if(dfs(0, 0, b[i])) printf("Y ");
		else printf("N ");
	}

}
