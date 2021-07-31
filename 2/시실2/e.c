#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle(int sig){
	int i;
	for(i=0; i<5; i++){
	printf("BEEP\n");
	sleep(1);
	}
	sleep(5);
	printf("I'm alive\n");
}

int main(){

	signal(SIGINT,handle);
	while(1);
}
