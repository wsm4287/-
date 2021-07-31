#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unistd.h"
#include "pthread.h"
#include <signal.h>

#define MAXLINE 80

int  cfd;

void *thread(void *arg){
	int n;
	char bf[MAXLINE];
	char buf[MAXLINE];
	char a[1];
	pthread_detach(pthread_self());
	while(1){
		int i=0;
		while((n=read(0,a,1))!=-1){
			if(a[0]=='\n'||a[0]=='\0')
				break;
			bf[i++]=a[0];
		}
		if(i!=0){
			bf[i]='\n';
			bf[i+1]='\0';
			write(cfd,bf,i+1);
		
			n=read(cfd,buf,MAXLINE);
			if(strncmp(buf,"BYE",3)==0){
				write(1,buf,n);
				break;
			}
			if(strncmp(buf,"Too many client\n",13)==0){
				break;
			}
			write(1,buf,n);
		}
	}

	close(cfd);
	return NULL;
}

int main (int argc, char *argv[]) {
	
	pthread_t tid;	
	void *thread_result;
	int n;
	char buf[MAXLINE];
	struct hostent *h;
	struct sockaddr_in saddr;
	
	char *host = argv[1];
	int port = atoi(argv[2]);

	if ((cfd= socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("socket() failed.\n");
		exit(1);
	}
	if ((h = gethostbyname(host)) == NULL) {
		printf("invalid hostname %s\n", host);
		exit(2);
	}

	bzero((char *)&saddr, sizeof(saddr));
	saddr.sin_family= AF_INET;
	bcopy((char *)h->h_addr, (char *)&saddr.sin_addr.s_addr, h->h_length);
	saddr.sin_port= htons(port);

	if (connect(cfd,(struct sockaddr*)&saddr,sizeof(saddr)) < 0) {
		printf("connect() failed.\n");
		exit(3);
	}

	pthread_create(&tid, NULL, thread, NULL);

	pthread_join(tid, &thread_result);

	close(cfd);
	return 0;
}	
