#include <stdio.h>


#define INF 9999999

int x[1000][1000];
int check[1000];
int d[1000][2];
int d2[1000];
int N;
int min;
int min2=99999;

int sig(int a){
	int k=0;
	for(int i=0; i<=a; i++)
		k += i;
	return k;
}

void find(){
	int i,j,a;
	check[0]=1;
	for(i=1; i<N; i++){
		d[i][0] = x[0][i];
	}
	for(i=0; i< N-1; i++){
		a = -1;
		for(j=0; j<N; j++){
			if(check[j]==1)
				continue;
			if(a==-1||d[a][0] > d[j][0])
				a=j;
		}
		
		min += d[a][0];
		check[a] = 1;
		
		for(j=0; j<N; j++){
			if(check[j]==1)
				continue;
			if(d[j][0] > x[a][j]){
				d[j][0] = x[a][j];
				d[j][1] = a;
			}
		}
	}
	
}

void find2(){
	int i,j,a;
	check[0]=1;
	
	for(i=0; i< N-1; i++){
		a = -1;
		for(j=0; j<N; j++){
			if(check[j]==1)
				continue;
			if(a==-1||d2[a] > d2[j])
				a=j;
		}
		
		min += d2[a];
		check[a] = 1;
		
		for(j=0; j<N; j++){
			if(check[j]==1)
				continue;
			if(d2[j] > x[a][j]){
				d2[j] = x[a][j];
			}
		}
	}
	
}


int main() {
	scanf("%d", &N);
	int i,j;
	int m=0;
	m = sig(N-1);
	int a,b,w;
	for(i=0; i<m; i++){
		scanf("%d %d %d", &a , &b, &w);
		x[a][b] = w;
		x[b][a] = w;
	}
	
	find();
	
	int q;
	int t =min;
	for(i=1; i<N; i++){
		min = 0;
		q = d[i][0];
		x[d[i][1]][i] = INF;
		x[i][d[i][1]] = INF;
		for(j=0; j<N; j++){
			check[j]=0;
			d2[j] = x[0][j];
		}
		find2();
		if(min2 > min){
			min2 = min;
		}
		if(min2 == t || min2 == t+1)
			break;
		x[d[i][1]][i] = q;
		x[i][d[i][1]] = q;
	}
	
	printf("%d\n%d", t, min2);

	return 0;
}