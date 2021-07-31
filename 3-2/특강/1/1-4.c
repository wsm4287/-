#include <stdio.h>

int main(){

	int n;
	scanf("%d", &n);
	int a[n],b[n];
	for(int i=0; i<n; i++){ 
		scanf("%d", &a[i]);
		int x=0;
		for(x=0; x< a[i]; x++){
			b[i-x] = b[i-x-1];
		}
		b[i-x] = i+1;
	}

	for(int i = 0; i<n; i++) printf("%d ", b[i]);	

	return 0;
}
