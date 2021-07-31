#include <stdio.h>

int x[110][110];

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
	for(i=0; i<110; i++){
		for(int j=0; j<110; j++){
			if(x[i][j] ==1){
				if(x[i-1][j]*x[i+1][j]*x[i][j-1]*x[i][j+1] != 1) y += 1;
				if((x[i-1][j]==0) && (x[i][j-1]==0)) y +=1;
				if((x[i+1][j]==0) &&(x[i][j+1]==0)) y+=1;	
				if((x[i+1][j]==0) &&(x[i][j-1]==0)) y+=1;
				if((x[i-1][j]==0) &&(x[i][j+1]==0)) y+=1;
			}
		}
	}

	printf("%d", y);


}
