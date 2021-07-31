#include <stdio.h>

int N;
int a[550][550];
int b[550];
int max=1;
void dis(int k){
	for(int i=0; i<max; i++){
		if(i != k) b[k] = b[k] + a[k][i];
	}
}


int main(){

	scanf("%d", &N);
	int q,w;
	for(int i=0; i<N; i++){
		scanf("%d %d", &q, &w);
		a[q-1][w-1] = 1;
		if(q > max) max = q;
		if(w > max) max = w;
	}	
	for(int i=0; i<max; i++){
		for(int j=0; j<max; j++){
			if(a[i][j] != 1) a[i][j] = 999999;
		}

	}
	for(int k=0; k<max; k++){
		for(int i=0; i<max; i++){
			for(int j=0; j<max; j++){
				if(a[i][j] >= a[i][k] + a[k][j]) a[i][j] = a[i][k] + a[k][j];
			}
		}
	}


	for(int i=0; i<max; i++) dis(i);
	float x=0;
	for(int i=0; i<max; i++) x += b[i];
	float ans = x/(max*(max-1));
	printf("%.3f", ans);
	return 0;
}
