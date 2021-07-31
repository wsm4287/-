#include <stdio.h>

int N;

int sigma(int n){
	if(n==1) return 1;	
	return sigma(n-1)+n;

}

int main(){

	scanf("%d", &N);
	printf("%d", sigma(N));

	return 0;
}
