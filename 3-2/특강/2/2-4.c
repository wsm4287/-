#include <stdio.h>

int N;
int a[1000];
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
  pivot = a[left]; 


  while(low < high){
    do {
      low++;
    } while (low<=right && a[low]<pivot);

    do {
      high--; 
    } while (high>=left && a[high]>pivot);
    if(low < high) swap(&a[low], &a[high]);

  }

  swap(&a[left], &a[high]);

  return high;
}

void quick(int left, int right){


  if(left<right){

    int q = partition(left, right); 

    quick(left, q-1);
    quick(q+1, right);
  }

}

int low_search(int x, int y, int k){
	int i, ans;
	ans = -1;
	while(x <= y){	
		i=(x+y)/2; 
		if(a[i] >= k){
			ans = i;
			y = i-1;
		}
		else x = i+1;
	}
	return ans;
}
int high_search(int x, int y, int k){
	int i, ans;
	ans = -1;
	while(x <= y){	
		i=(x+y)/2; 
		if(a[i] <= k){
			ans = i;
			x = i+1;
		}
		else y = i-1;
	}
	return ans;
}
int main(){

	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++) scanf("%d", &a[i]);
	quick(0, N-1);
	int x=0;
	int j,k,q, p;

/*	for(i=0; i<N-2; i++){
		for(j=i+1; j<N-1; j++){
			p = a[j]- a[i];
			for(k=j+1; k<N; k++){
				q = a[k]-a[j];
				if(p <= q && q <= 2*p) x++;
			}
		}
	}
*/
	int low, high;
	for(i=0; i<N-2; i++){
		for(j=i+1; j<N-1; j++){
			p = a[j]- a[i];
			low = low_search(0, N-1, a[j]+p);
			if(low == -1) break;
			high = high_search(0, N-1, a[j]+ 2*p);
			x += high - low + 1;
		}
	}


	printf("%d", x);
	return 0;
}
