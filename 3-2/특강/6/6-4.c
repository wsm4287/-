#include <stdio.h>

int T, K;

int a[7]={1,2,4,8,16,32,64};
int ans;

void subset(int n, int k){
	if(n==7) return;
	if(k==K){
		ans++;
		return;
	}
	else if(k > K) return;
	subset(n, k+a[n]);
	subset(n+1, k);

}


int main(){
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &K);
		subset(0, 0);
		printf("%d\n", ans);
		ans = 0;
	}


	return 0;
}
