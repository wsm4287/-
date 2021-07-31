#include <stdio.h>

int x[100][100];

int main(){

	int n;
	scanf("%d", &n);
	int i;
	int a,b;
	for(i=0; i<n; i++){
		scanf("%d %d", &a, &b);
		for(int j=0; j<10; j++){
			for(int k=0; k<10; k++){
				x[a+j][b+k] = 1;
			}
		}
	}

	int y=0;
	for(i=0; i<100; i++){
		for(int j=0; j<100; j++) y += x[i][j];
	}
	printf("%d", y);


}
