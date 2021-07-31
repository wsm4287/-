#include "types.h"
#include "user.h"
#include "param.h"
#include "fcntl.h"


int *mem;
int **k;
int main(int argc, char**argv){
	printf(1,"ktest\n");
	int j;
	for (int i=0;i<50;i++){
		k[i] = malloc(40960);
		for(j=0; j<10240; j++){
			k[i][j]=j+i;
		}
		//swapstat(&x,&y);
		//printf(1, "%d, %d\n", x,y);
	}
	for(int i=0; i<50; i++){
		for(j=0; j<10240; j++) if(k[i][j]);
		//swapstat(&x, &y);
		//printf(1, "%d, %d\n", x,y);
	}
	

	printf(1, "=== TEST END ===\n");
	exit();

/*	for(int i=0; i<50; i++){
		//printf(1,"%d\n", i);
		if(fork()==0)
			sleep(100);
	}
	int x,y;
	swapstat(&x, &y);
	printf(1, "%d , %d\n", x, y);
*/	
}
