#include "types.h"
#include "user.h"
#include "param.h"
#include "fcntl.h"


int *mem;
int *k;
int main(int argc, char**argv){
	printf(1,"ktest\n");
	int x,y,j;
	mem = malloc(40960);
	for(int i=0; i<60; i++){
		k = malloc(40960);
		for(j=0; j<10240; j++) k[j]=j+1;
		swapstat(&x, &y);
		printf(1, "before : %d %d\n", x,y);
	}
	if(fork()==0){
		swapstat(&x,&y);
		printf(1, "fork : %d, %d\n", x,y);
	}
	for(int i=0; i<10240; i++)
		mem[i]=i;
	wait();
	swapstat(&x, &y);
	printf(1, "after : %d, %d\n", x,y);
	printf(1, "=== TEST END ===\n");
	exit();

}
