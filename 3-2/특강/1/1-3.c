#include <stdio.h>

int main(){

	int N,i,j;
	scanf("%d", &N);
	int a[N][N];
	int x[N];
	int y[N];
	
	for(i=0; i<N; i++) x[i]= y[i] = 0;

	for(i=0; i<N; i++){
		for(j=0; j<N; j++){ 
			scanf("%d", &a[i][j]);
			x[i] += a[i][j];
		}
	}
	
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			y[i] += a[j][i];
		}
	}
	
	int x1 = x[0];
	int y1 = y[0];
	int k1=0;
	int q1=0;

	int x2 = x[0];
	int y2 = y[0];
	int k2 =0;
	int q2 = 0;
	
	for(i=0; i<N; i++){
		if(x1 < x[i]){
			x1=x[i];
			k1 = i;
		}
		if(y1 < y[i]){
			y1=y[i];
			q1 = i;
		}	

		if(x2 > x[i]){
			x2=x[i];
			k2 = i;
		}
		if(y2 > y[i]){
			y2=y[i];
			q2=i;
		}
		
	}
	if(x1 == y1) printf("%d %d", k2+1, q2+1);
	else printf("%d %d ", k1+1, q1+1);
	
	return 0;
}
