#include <stdio.h>

int main(){
	int i=0;
	char a[100];
	int x=0;
	scanf("%s", a);
	while(a[i]){
		if(i == 0){
			x +=10;
			i++;
			continue;
		}
		if(a[i] == a[i-1]) x += 5;
		else x+=10;
		i++;
	}
	printf("%d", x);

	return 0;
}
