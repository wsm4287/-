#include <stdio.h>

int N;

int fibo(int n){
	if(n==0) return 0;
	if(n==1) return 1;	
	return fibo(n-1) + fibo(n-2);

}

int main(){

	scanf("%d", &N);
	printf("%d", fibo(N));

	return 0;
}
