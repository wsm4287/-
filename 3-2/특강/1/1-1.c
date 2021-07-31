#include <stdio.h>





int main(){


	int a[9];
	int i,x,y;
	x = 0;
	for(i=0; i<9; i++){ 
		scanf("%d", &a[i]);
		if(x < a[i]){ 
			x = a[i];
			y = i+1;
		}
	}
		
	printf("%d\n%d", x, y);
	



	return 0;


}
