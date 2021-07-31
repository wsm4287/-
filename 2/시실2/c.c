#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>
#define MAXLINE 80

int ccount=0;
int N=5;
pid_t pid[5];
void handler(int sig){
	pid_t pid = wait(NULL);
	ccount--;
	printf("Recived signal %d from %d pid\n",sig,pid);
}

int main()
{	
	int i;
	ccount = N;
	signal (SIGCHLD, handler);
	for(i=0; i<N; i++){
		if((pid[i] = fork())==0)
			exit(0);
	}
	while(ccount >0)
		sleep(5);
} 
