#include <stdio.h>

char a[30];
int c[30];
int main(){
	int i=0;
	scanf("%s", a);
	for(i=0; a[i]; i++){
		if(('a' <= a[i] )&& (a[i] <= 'z')) c[a[i]-'a'] += 1;
	}
	
	int x=0;
	int y=0;
	for(i=0; i<30; i++){
		if(c[x] < c[i]) x= i;
	}

	if(x != 0){
		for(i=0; i<30; i++){
			if(c[i] == c[x]){
				x = i;
				break;
			}
		}
	}

	printf("%c", x+'a');

	return 0;

}
