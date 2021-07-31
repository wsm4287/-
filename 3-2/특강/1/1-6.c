#include <stdio.h>

int a[1000];
int b[1000];
int c[1000];

int main(){

	int n;
	scanf("%d", &n);
	int i;
	int j;
	for(i=0; i<n; i++){ 
		scanf("%d",&a[i]);
		c[i] = a[i];
		while(c[i]){
			b[i] += c[i] % 10; 
			c[i] = c[i] / 10;
		}
		while(b[i] >= 10){
			c[i] = b[i];
			b[i] = 0;
			while(c[i]){
				b[i] += c[i] % 10; 
				c[i] = c[i] / 10;
			}
		}
	}


	int x=0;
	for(i=0; i<n; i++){
		if(b[x] < b[i]) x = i;
	
	}
	int k = a[x];
	for(i=0; i<n; i++){
		if(b[i] == b[x]){
			if(k > a[i]) k = a[i];
		}
	}

	printf("%d", k);

}
