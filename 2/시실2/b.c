#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 80

int main()
{
	int n, fd[2];
	pid_t pid;
	char line[MAXLINE];
	if(pipe(fd) < 0) exit(1);
	if((pid=fork()) < 0) exit(2);
	
	if(pid > 0 ){
		close(fd[0]);
		dup2(fd[1],1);
		execl("/bin/echo", "echo","124 * (42+3) % 17", NULL); 
	}
	else{
		close(fd[1]); 	
		dup2(fd[0],0);
		execl("/usr/bin/bc", "bc",NULL);
	}
	exit(0);
} 




