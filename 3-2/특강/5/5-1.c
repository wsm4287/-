#include <stdio.h>

int N, T, B;
int H[30];
int min;


void dfs(int k, int sum){
	if(k==N){
		if(sum>=B) if(min > sum - B) min = sum - B;
		return;
	}
	dfs(k+1, sum + H[k]);
	dfs(k+1, sum);


}


int main(){

	scanf("%d", &T);
	int i;
	for(i=0; i<T; i++){
		scanf("%d %d", &N, &B);
		for(int j=0; j<N; j++) scanf("%d", &H[j]);
		min = B;
		dfs(0,0);
		printf("%d\n", min);
	}



	return 0;

}
