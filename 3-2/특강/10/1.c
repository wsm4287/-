#include <stdio.h>

int n;
int min = 10;

int main(){

	scanf("%d", &n);
	int k;
	int check = 0;
	char q;
	for(int i=0; i<n; i++){
		scanf("%d %c", &k, &q);
		if(q == 'Y'){
			if(min > k) min = k;
		}
		else{
			if(k >= min) check = 1;
		}
	}
	if(check == 1) printf("F");
	else if(min == 10) printf("F");
	else printf("%d", min);

	return 0;
}
