#include <stdio.h>

char a[110][110];

char b[110][110];

int find(int x, int y, int p){

	int i,j;
	for(i=0; i<p; i++){
		for(j=0; j<p; j++){
			if(a[x+i][y+j] != b[i][j]) return 0;
		}
	}
	return 1;

}

int main(){

	int M;
	scanf("%d", &M);
	int i,j;
	for(i=0; i<M; i++){
		scanf("%s", &a[i]);
	}


	int p;
	scanf("%d", &p);
	for(i=0; i<p; i++){
		scanf("%s", &b[i]);
	}

	int X=0;
	for(i=0; i<M; i++){
		for(j=0; j<M; j++){
			if(a[i][j] == b[0][0]) X +=find(i,j,p);
		}
	}
	printf("%d", X);
	return 0;
}
