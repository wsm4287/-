#include <stdio.h>

int N,T;
int a[50000];

int search(int b, int c, int x){
	int i;
	while(b<=c){
		i = (b+c)/2;
		if(a[i] == x) return i+1;
		else if(a[i] > x) c = i-1;
		else b = i+1;
	}


	return 0;

}

int main(){

	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++) scanf("%d", &a[i]);
	scanf("%d", &T);
	int x;
	for(i=0; i<T; i++){
		scanf("%d", &x);
		x = search(0,N-1,x);
		printf("%d\n", x);	

	}

	return 0;
}
