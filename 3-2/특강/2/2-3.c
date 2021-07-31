#include <stdio.h>

int N, M, x;
int a[10000];
int max;

int check(int m){
	int z = 0;
	for(int i=0; i<N; i++){
		if(a[i] > m) z+= m;
		else z += a[i];
	}
	return z;
}


int main(){
	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++){ 
		scanf("%d", &a[i]);
		if(max < a[i]) max = a[i];
		x += a[i];
	}
	scanf("%d", &M);
	if(x <= M) printf("%d", max);
	else{
		int s, sol, m, sum;
		s = sol = 0;
		while (s<=max){
			m = (s+max)/2;
			sum = check(m);
			if(sum <= M){
				sol = m;
				s = m+1;
			}
			else max = m-1;
		}	
		printf("%d", sol);
	}
	return 0;
}
