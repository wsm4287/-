#include <stdio.h>
 
int N;

int w[30];
int check[30];
int max;


int add(int sum, int k){
	int a = sum;
	int b = k;
	if(sum > k){
		while(b){
			if(a%10 + b %10 > 9) return -1;
			a = a/10;
			b = b/10;
		}
	}
	else{
		while(a){
			if(a%10 + b %10 > 9) return -1;
			a = a/10;
			b = b/10;
		}
	}
	return 1;
}


void dfs(int k, int sum){
	if(max < k) max = k;
	if(k==N) return;
	for(int i=0; i<N; i++){
		if(check[i]==0){
			if(add(sum, w[i])==1){
				if(max > k+1) return;
				check[i] = 1;
				dfs(k+1, sum+ w[i]);
				check[i] = 0;
			}
		}

	}

}
 

int main(void)
{
	scanf("%d", &N);
	int i;
	for(int i=0; i<N; i++) scanf("%d", &w[i]);  
	dfs(0, 0);
	printf("%d", max);
	return 0;
}