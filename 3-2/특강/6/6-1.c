#include <stdio.h>

int N,k;

int a[15];
int b[1000000];
int cnt;

void dfs(int n, int sum){
	if(n == N){
		b[cnt++] = sum;
		return;
	}
	dfs(n+1, sum+a[n]);
	dfs(n+1, sum);
	

}

void swap(int* i, int* j){
	int temp = *i;
	*i = *j;
	*j = temp;

}

int partition(int left, int right){
	int pivot;
	int low, high;
	low = left;
	high = right + 1;
	pivot = b[left];
	
	while(low < high){
		do{
			low++;
		}while(low<=right && b[low] < pivot);
		
		do{
			high--;
		}while(high>=left && b[high] > pivot);
		if(low < high) swap(&b[low], &b[high]);

	}

	swap(&b[left], &b[high]);
	return high;



}

void quick(int left, int right){

	if(left< right){
		int q = partition(left, right);
		quick(left, q-1);
		quick(q+1, right);
	}


}


int main(){

	scanf("%d %d", &N, &k);
	int i,j;
	for(i=0; i<N; i++) scanf("%d", &a[i]);
	dfs(0,0);
	quick(0, cnt-1);

	int c[cnt];

	for(i=0; i<cnt; i++){
		c[i] = b[cnt-1-i] ;
	}

	int t=0;
	i = 0;
	while(c[i] != k){
		if(c[i] == c[i-1]) t++;
		i++;
	}
	printf("%d", i-t+1);
	return 0;
}
