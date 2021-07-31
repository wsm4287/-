#include <stdio.h>

int R,C;

char a[55][55];

int find(){
	int k=0;
	int i,j;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(a[i][j] == 'o'){
				if(a[i-1][j-1] == 'o') k+=1;
				if(a[i-1][j] == 'o') k+=1;
				if(a[i-1][j+1] == 'o') k+=1;
				if(a[i][j-1] == 'o') k+=1;
				if(a[i][j+1] == 'o') k+=1;
				if(a[i+1][j-1] == 'o') k+=1;
				if(a[i+1][j] == 'o') k+=1;
				if(a[i+1][j+1] == 'o') k+=1;
			}
		}
	}

	return k/2;


}

int main(){

	scanf("%d %d", &R, &C);
	int i,j;
	for(i=0; i<R; i++){
		scanf("%s", &a[i]);
	}
	int k=0;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(a[i][j] == '.'){ 
				a[i][j] = 'o';
				if(k < find()) k = find();
				a[i][j] = '.';
			}
			
		}
	}

	if(k==0){
		for(i=0; i<R; i++){
			for(j=0; j<C; j++){
				if(a[i][j] == 'o'){
					if(a[i-1][j-1] == 'o') k+=1;
					if(a[i-1][j] == 'o') k+=1;
					if(a[i-1][j+1] == 'o') k+=1;
					if(a[i][j-1] == 'o') k+=1;
					if(a[i][j+1] == 'o') k+=1;
					if(a[i+1][j-1] == 'o') k+=1;
					if(a[i+1][j] == 'o') k+=1;
					if(a[i+1][j+1] == 'o') k+=1;
				}
			}
		}
		k = k/2;
	}

	printf("%d", k);
}
