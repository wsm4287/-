#include <stdio.h>

int N,M;
int a[200000];

int search(int b, int c, int x){
	int i=0;
	int ans=0;
	while(b<=c){
		i = (b+c)/2;
		if(a[i] == x){
			while(a[i] == x) i--;
			return i+1;
		}
		else if(a[i] > x) c = i-1;
		else b = i+1;
	}
	return 0;

}

int check(int x, int y){
	int i = y;
	int ans=0;
	while(a[i++] == x) ans++;

	return ans;
}

int main(){

	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++) scanf("%d", &a[i]);
	scanf("%d", &M);
	int x, y, ans;
	for(i=0; i<M; i++){
		scanf("%d", &x);
		y = search(0,N-1,x);
		ans = check(x, y);
		printf("%d ", ans);	

	}

	return 0;
}
