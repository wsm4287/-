 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <strings.h>
 #include <arpa/inet.h>
 #include "unistd.h"
 #include <signal.h>
 #include <sys/wait.h>
 #include <time.h>
 #include <string.h>
 #include "pthread.h"
 #include "db.h"
 
 #define MAXLINE 80 

db_t *DB;

int N=0;	
int *connfdp;
int listenfd;
int idx;
int connfd;
int size;
int x=0;
int b=0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t w = PTHREAD_MUTEX_INITIALIZER;
pthread_t tid[10];

void end(int sig){
	for(int i=0; i<idx; i++){
		pthread_cancel(tid[i]);
		pthread_join(tid[i],NULL);
		close(connfdp[i]);
	}
	db_close(DB);
	close(listenfd);
	free(connfdp);
	exit(0);

}


void *thread(void *c){
	char key[MAXLINE];
	char buf[MAXLINE];
	int n;
	int cnt, buf_len, val_len;
	pthread_mutex_lock (&lock);
	int my = idx;
	idx++;
	pthread_mutex_unlock (&lock);
	pthread_detach(pthread_self());
	int i=0;
	int k=0;
	char *val;
	while ((n = read( connfdp[my], key, MAXLINE)) > 0)
                {
		if(strncmp(key,"CONNECT\n",7)==0){
			key[7]='\0';
			strcat(key,"_ok\n");
                        		if(write(connfdp[my], key, n+3));
			break;
		}
	}
	while ((n = read( connfdp[my], key, MAXLINE)) > 0)
                {
		pthread_mutex_lock (&lock);
		b++;
		if(b==1)
			pthread_mutex_lock (&w);
		pthread_mutex_unlock (&lock);
		if(strncmp(key,"DISCONNECT\n",10)==0){
			strcpy(key,"BYE\n");
			if(write(connfdp[my], key, 4));
			idx--;
			return NULL;
		}
		else{
			strcpy(buf,key);
			buf[n]='\0';
			i=0;
			k=0;
			while(buf[i]!='\0'){
				if(buf[i]==' ')
					break;
				i++;
			}
			if(i==n){
				if(write(connfdp[my],"UNDEFINED PROTOCOL\n", 19));
				continue;
			}
			i=i+2;
			while(i!=n)
				buf[k++]=buf[i++];
			buf[k-1]='\0';
			buf_len = strlen(buf);
			if(strncmp(key,"GET",3)==0){
				char v[15];
				buf[k-2]='\0';
				buf_len--;
				val = db_get(DB, buf, buf_len, &val_len);
				if (val == NULL) {
					if(write(connfdp[my],"GETINV\n", 7));
				} else{
					strcpy(key, "GETOK [");
					strcat(key, buf);
					sprintf(v, "[%d]\n", *((int *)val));
					strcat(key, "] ");
					strcat(key, v);
					if(write(connfdp[my], key, strlen(key)));
				}
			}
			else if(strncmp(key,"PUT",3)==0){		
				val = (char*)malloc(sizeof(int));
				i=0;
				k=0;
				char a[15];
				while(buf[i]!='\0'){
					if(buf[i]==' ')
						break;
					i++;
				}
				int t =i;
				if(i==buf_len){
					if(write(connfdp[my],"UNDEFINED PROTOCOL\n", 19));
					continue;
				}
				i=i+2;
				while(buf[i]!=']')
					a[k++]=buf[i++];
				buf[t-1]='\0';
				a[k]='\0';
				*(int*)val = atoi(a);
				cnt = *((int*)val);
				db_put(DB, buf,strlen(buf), (char *)&cnt, sizeof(int));
				if(write(connfdp[my], "PUTOK\n",6));
			}
			else{
				if(write(connfdp[my],"UNDEFINED PROTOCOL\n", 19));
				continue;
			}

			
		}
		pthread_mutex_lock (&lock);
		b--;
		if(b==0)
			pthread_mutex_unlock (&w);
		pthread_mutex_unlock (&lock);
        }
	free(val);
	return NULL;

}


int main ( int argc , char * argv []) 
{
	signal(SIGINT,end);
	signal(SIGTSTP,end);
	int caddrlen ;
	struct sockaddr_in saddr, caddr ;
	int port =atoi ( argv [1]);
	size = atoi(argv[3]);
	x = atoi(argv[2]);

	DB = db_open(size);

	if (( listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf ("socket() failed.\n");
		exit(1);
	}

	bzero ((char *)& saddr, sizeof ( saddr ));
	saddr.sin_family = AF_INET;
	saddr.sin_addr.s_addr =	htonl (INADDR_ANY);
	saddr.sin_port =htons (port);
	
	if (bind( listenfd , ( struct sockaddr *)& saddr, sizeof ( saddr )) < 0) {
		printf ("bind() failed.\n");
		exit(2);
	}


	if (listen( listenfd , 5) < 0) {
		printf ("listen() failed.\n");
		exit(3);
	}
 	connfdp = (int *)malloc(sizeof(int)*10);
	 while (1) { 
		
		caddrlen = sizeof ( caddr );
		if (( connfd = accept( listenfd , ( struct sockaddr *)& caddr , & caddrlen )) < 0) {
			printf ("accept() failed.\n");
			continue;
		}	
		
		pthread_mutex_lock (&lock);
		connfdp[idx] =connfd;
		pthread_mutex_unlock (&lock);	
		if(idx < x)
			pthread_create(&tid[idx], NULL,thread, connfdp );
		else{
			printf("Too many client\n");
			if(write(connfdp[idx], "Too many client\n", 16));
			close(connfdp[idx]);
		}
		
	}
	close(listenfd);
	printf ("connection terminated.\n");
	db_close(DB);
	free(connfdp);
	return 0;
}



 
