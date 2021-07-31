#include <stdio.h>

int a[2][30000];
int b[2][30000];
void swap(int *x, int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


int partition(int left, int right){
  int pivot;
  int low, high;

  low = left;
  high = right + 1;
  pivot = a[1][left]; 


  while(low < high){
    do {
      low++;
    } while (low<=right && a[1][low]<pivot);

    do {
      high--; 
    } while (high>=left && a[1][high]>pivot);
    if(low < high){ 
      swap(&a[1][low], &a[1][high]);
      swap(&a[0][low], &a[0][high]);
    }

  }

  swap(&a[1][left], &a[1][high]);
  swap(&a[0][left], &a[0][high]);

  return high;
}

void quick(int left, int right){


  if(left<right){

    int q = partition(left, right); 

    quick(left, q-1);
    quick(q+1, right);
  }

}

int main(){
	int N;
	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++){ 
		a[0][i] = i+1;
		scanf("%d", &a[1][i]);
	}

	quick(0, N-1);

	for(i=0; i<N; i++){
		b[0][N-i-1] = a[0][i];
		b[1][N-i-1] = a[1][i];
	}
	i = 0;
	while(i<N){
		if(b[1][i] == b[1][i+1]){
			if(b[0][i] > b[0][i+1]) swap(&b[0][i], &b[0][i+1]);
		}
		i++;
	}
	printf("%d %d %d", b[0][0], b[0][1], b[0][2]);
	return 0;
}
