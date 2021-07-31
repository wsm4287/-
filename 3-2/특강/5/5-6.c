#include <stdio.h>

int Y, X;

int a[1100][1100];
int b[1100][1100];

int main(){

	scanf("%d %d", &Y, &X);
	int i,j;
	for(i=0; i<Y; i++){
		for(j=0; j<X; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0; i<Y; i++){
		for(j=0; j<X; j++){
			if(a[i][j] ==1){
				b[i][j] =1;
				if(a[i][j-1] != 0) b[i][j] = b[i][j] + b[i][j-1];
			}
		}

	}

	for(i=0; i<Y; i++){
		for(j=0; j<X; j++){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;

}
