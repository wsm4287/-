#define _GNU_SOURCE

#include "db.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_KEYLEN 1024


int main(int argc, char *argv[])
{
	db_t *DB;
	char key[MAX_KEYLEN];
	char *val;
	int size;
	int ret, cnt, key_len, val_len;
	int log_fd, dir_fd;

	if (argc != 2) {
		printf("Usage: %s size\n", argv[0]);
		return -1;
	}

	size = atoi(argv[1]);
	DB = db_open(100);
	if (DB == NULL) {
		printf("DB not opened\n");
		return -1;
	}
	printf("DB opened\n");

	if ((log_fd = open("./db_log", O_RDWR|O_CREAT|O_DIRECT, 0755)) < 0) {
		perror("open db_log");
		exit(1);
	}
	posix_fallocate(log_fd, 0, 4096*256*256);  // 256MB
	printf("DB log file opened\n");

	
	char buf[MAX_KEYLEN];
	int n;
	char a[1];
	while (1){
		int i=0;
		while((n=read(0,a,1))!=-1){
			if(a[0]=='\n'||a[0]=='\0')
				break;
			key[i++]=a[0];
		}
		if(i!=0){
			n = i;
			key[i]='\n';
			key[i+1] = '\0';
			int k=0;
			strcpy(buf,key);
			buf[n]='\0';
			i=0;
			while(buf[i]!='\0'){
				if(buf[i]==' ')
					break;
				i++;
			}
			i=i+2;
			while(i!=n)
				buf[k++]=buf[i++];
			buf[k-1]='\0';
			int buf_len = strlen(buf);
			if(strncmp(key,"GET",3)==0){
				buf_len = strlen(buf);
				val = db_get(DB, buf, buf_len, &val_len);
				if (val == NULL) {
					printf("GETOK [%s] [NULL]\n", buf);
					cnt = 1;
				} else {
					printf("GETOK [%s] [%d]\n", buf, *((int *)val));
					cnt = *((int*)val) + 1;
					free(val);
				}
				db_put(DB, buf, buf_len, (char *)&cnt, sizeof(int));
			}	
			else if(strncmp(key,"PUT",3)==0){
				printf("PUTOK\n");	

			}
			else{
				break;
			}
		}
	}


	db_close(DB);
	printf("DB closed\n");
	return 0;
}
