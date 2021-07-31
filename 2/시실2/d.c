#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


void handler(int sig){

	printf("BEEP\n");
	alarm(1);
	
}

int main()
{	
	signal (SIGALRM, handler);
	alarm(1);
	while(1);
	
} 
