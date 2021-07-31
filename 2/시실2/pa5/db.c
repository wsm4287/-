/*-----------------------------------------------------------
 *
 * SSE2033: System Software Experiment 2 (Fall 2019)
 *
 * Skeleton code for PA #1
 * 
 * CSI Lab, Sungkyunkwan University
 *
 * Student Id   :	2016310936
 * Student Name :	우승민
 *
 *-----------------------------------------------------------
 */

#include "db.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <fcntl.h>

int t;
char max[100];
char nu[100];
int num;

db_t *db_open(int size)
{
	db_t *db = NULL;
	db = (db_t*)malloc(sizeof(db_t)*size);
	t=size;
	int i;
	for(i=0; i<size; i++){
		db[i].word=NULL;
		db[i].next = NULL;
		}

	int child_status;
	if(fork() == 0){
		execl("/bin/mkdir", "mkdir ", "-p", "db", NULL);

	}
	wait(&child_status);	
	
	const char *file = "a.txt";

	
	if(fork()==0){
		int fd =open(file, O_RDWR|O_CREAT, 0755);
		dup2(fd,1);
		execl("/bin/ls", "ls", "db", NULL);
	}
	wait(&child_status);	
	int fd =open(file, O_RDONLY, 0755);
	int z;
	int p=0;
	max[0]='0';
	char buffer[1];
	while(1){
		while((z = read(fd, buffer,1))==1){	
			nu[p++]=buffer[0];	
			if(buffer[0]=='\n')
				break;	
		}

		if(p>strlen(max)){
			for(int t=0; t<p; t++)
				max[t]=nu[t];
			}
		else if(p==strlen(max)){
			if(strcmp(nu,max)==1){
				for(int t=0; t<p; t++)
					max[t]=nu[t];
				}
		}		
		p=0;
		if(z==0)
			break;
	}
	close(fd);
	num = atoi(max);
	return db;
}

void db_close(db_t *db)
{

	const char *file_src2 = NULL;
	int fd_src2;
	char *b= (char*)malloc(sizeof(char)*100);
	strcat(b,"./db/");
	char *ff = (char*)malloc(sizeof(char)*10);
	num++;
	sprintf(ff,"%d",num);
	strcat(b,ff);
	file_src2 =b;
	fd_src2 = open(file_src2, O_RDWR|O_CREAT, 0755);
	int s=0;
	while(s<t){
		db_t *sa = &db[s];
		while(sa->word){
			char *cc = (char*)malloc(sizeof(char)*10);
			if(write(fd_src2, sa->word, strlen(sa->word)));
			if(write(fd_src2, " ",1));
			sprintf(cc,"%d", sa->count);
			if(write(fd_src2, cc, strlen(cc)));
			if(write(fd_src2, "\n",1));
			free(cc);
			if(sa->next == NULL)
				break;
			sa = sa->next;
			}
		s++;
	}
	close(fd_src2);
	free(b);
	free(ff);

	int i=0;
	db_t* temp = (db_t *)malloc(sizeof(db_t));
	db_t* cur = (db_t *)malloc(sizeof(db_t));
	for(i=0; i<t; i++){
		if(db[i].word == NULL)
			continue;
		if(db[i].next != NULL){
			cur = db[i].next;
			while(cur->next != NULL){
				temp = cur ->next;
				free(cur->word);
				free(cur);
				cur = temp;
			}
			temp = cur;
			free(temp->word);
			free(temp);
		}
	}	
	for(i=0; i<t; i++){
		if(db[i].word != NULL)
			free(db[i].word);
		}
	free(cur);
	free(db);

}

int ss=0;
void db_put(db_t *db, char *key, int key_len,
			char *val, int val_len)
{	
	db_t *temp = (db_t *)malloc(sizeof(db_t));
	temp -> word = (char*)malloc(sizeof(char)*(key_len+1));
	temp ->word[key_len]='\0';
	int k;
	temp -> count=*(int*)val;
	temp -> next = NULL;
	for(k=0; k<key_len; k++)
		temp -> word[k]= key[k];
	int x=key[0]-65;
	if(x>=t)
		x = x%t;
	db_t *cur = &db[x];
	if(*(int*)val==1){
		if(ss==t){
			const char *file_src2 = NULL;
			int fd_src2;
			char *b= (char*)malloc(sizeof(char)*100);
			strcat(b,"./db/");
			char *ff = (char*)malloc(sizeof(char)*10);
			char *fff = (char*)malloc(sizeof(char)*10);
			num++;
			sprintf(ff,"%s%d",b,num);
			sprintf(fff,"ex %d", num);
			strcat(b,fff);
			file_src2 =b;
			fd_src2 = open(file_src2, O_RDWR|O_CREAT, 0755);
			int s=0;
			while(s<t){
				db_t *sa = &db[s];
				while(sa->word){
					char *cc = (char*)malloc(sizeof(char)*10);
					if(write(fd_src2, sa->word, strlen(sa->word)));
					if(write(fd_src2, " ",1));
					sprintf(cc,"%d", sa->count);
					if(write(fd_src2, cc, strlen(cc)));
					if(write(fd_src2, "\n",1));
					free(cc);
					if(sa->next == NULL)
						break;
					sa = sa->next;
				}
				s++;
			}
			rename(file_src2,ff);
			db_t *cc = (db_t *)malloc(sizeof(db_t));
			db_t *tt = (db_t *)malloc(sizeof(db_t));
			int i;
			for(i=0; i<t; i++){
				if(db[i].word == NULL)
					continue;
				if(db[i].next != NULL){
					cc = db[i].next;
					while(cc->next != NULL){
						tt = cc ->next;
						free(cc->word);
						free(cc);
						cc = tt;
					}
					tt = cc;
					free(tt->word);
					free(tt);
				}
			}	
			for(i=0; i<t; i++){
				if(db[i].word !=NULL){
					free(db[i].word);
					}
				db[i].word=0;
				db[i].next=NULL;
				}
			close(fd_src2);
			free(b);
			free(ff);
			free(fff);
			ss=0;
			
		}
		if(db[x].word==0){
			db[x].word=temp->word;
			db[x].count=temp->count;
			db[x].next=NULL;	
			free(temp);
			ss++;
			return ;
			}
		else{
			while(1){
				if(cur -> next == NULL)
					break;
				cur = cur ->next;
				}
			cur -> next = temp;
			ss++;
			return ;
			}
	
		}
	else{ 
		while(cur->word!=NULL){
			if(strcmp(cur->word,key)==0){
				cur->count = temp -> count;
				free(temp);
				return;
				}	
			if(cur->next==NULL)
				break;
			cur = cur-> next;
			}

		if(ss==t){
			const char *file_src2 = NULL;
			int fd_src2;
			char *b= (char*)malloc(sizeof(char)*100);
			strcat(b,"./db/");
			char *ff = (char*)malloc(sizeof(char)*10);
			num++;
			sprintf(ff,"%d",num);
			strcat(b,ff);
			file_src2 =b;
			fd_src2 = open(file_src2, O_RDWR|O_CREAT, 0755);
			int s=0;
			while(s<t){
				db_t *sa = &db[s];
				while(sa->word){
					char *cc = (char*)malloc(sizeof(char)*10);
					if(write(fd_src2, sa->word, strlen(sa->word)));
					if(write(fd_src2, " ",1));
					sprintf(cc,"%d", sa->count);
					if(write(fd_src2, cc, strlen(cc)));
					if(write(fd_src2, "\n",1));
					free(cc);
					if(sa->next == NULL)
						break;
					sa = sa->next;
				}
				s++;
			}
			db_t *cc = (db_t *)malloc(sizeof(db_t));
			db_t *tt = (db_t *)malloc(sizeof(db_t));
			int i;
			for(i=0; i<t; i++){
				if(db[i].word == NULL)
					continue;
				if(db[i].next != NULL){
					cc = db[i].next;
					while(cc->next != NULL){
						tt = cc ->next;
						free(cc->word);
						free(cc);
						cc = tt;
					}
					tt = cc;
					free(tt->word);
					free(tt);
				}
			}	
			for(i=0; i<t; i++){
				if(db[i].word !=NULL){
					free(db[i].word);
					}
				db[i].word=0;
				db[i].next=NULL;
				}
			close(fd_src2);
			free(b);
				free(ff);
			ss=0;
		}

		if(db[x].word==0){
			db[x].word=temp->word;
			db[x].count=temp->count;
			db[x].next=NULL;	
			free(temp);
			ss++;
			return ;
			}
		else{
			cur ->next = temp;
			ss++;
			return ;
			}

		}


}
char n[100];
char c[5];
char save[100];
/* Returns NULL if not found. A malloc()ed array otherwise.
 * Stores the length of the array in *vallen */	
char *db_get(db_t *db, char *key, int key_len,
			int *val_len)
{
	char *value = NULL;
	int x=key[0]-65;
	if(x>=t)
		x = x%t;
	db_t * cur = &db[x];
	char buffer[1];
	int fd_src1;
	int i;
	if(db[x].word==NULL) {
		if(num==0){
			return value;
			}
		const char *file_src1 = NULL;
		for(i=num; i>=0; i--){
			char *b= (char*)malloc(sizeof(char)*100);
			strcat(b,"./db/");
			char *ff = (char*)malloc(sizeof(char)*10);
			sprintf(ff,"%d",i);
			strcat(b,ff);
			file_src1 = b;
			fd_src1 = open(file_src1, O_RDONLY, 0755);
			int a;
			while(1){
				int p=0;
				while((a=read(fd_src1,buffer,1))==1){
					if(buffer[0]==' ')
						break;
					save[p++]=buffer[0];
					}
				save[p]='\0';
				if(save[0]=='\0')
					break;		
				if(strcmp(save, key)==0){
					int k=0;
					while((a=read(fd_src1,buffer,1))==1){
						if(buffer[0]=='\n')
							break;
						c[k++]=buffer[0];
						}
					c[k]='\0';
					int temp = atoi(c);
					value = (char*)malloc(sizeof(int));     
					*(int*)value = temp;
					close(fd_src1);
					free(b);
					free(ff);
					return value;
					}
				else{
					while((a=read(fd_src1,buffer,1))==1){
						if(buffer[0]=='\n')
							break;
						}
					}
				}
			free(b);
			free(ff);
			close(fd_src1);
			}	
		}	
	else{
		while(1){
			if(cur->next == NULL){
				break;
			}
			if(strcmp(key,cur->word)!=0)
				cur = cur->next;
			else
				break;
			}

		if(cur->word!=NULL){
			if(strcmp(key,cur->word)==0){
				value = (char*)malloc(sizeof(int));     
				*(int*)value = cur -> count;
				return value;
				}
			else{
				if(num == 0){
					return value;
					}
				const char *file_src1 = NULL;
				for(i=num; i>=0; i--){
					char *b= (char*)malloc(sizeof(char)*100);
					strcat(b,"./db/");
					char *ff = (char*)malloc(sizeof(char)*10);
					sprintf(ff,"%d",i);
					strcat(b,ff);
					file_src1 = b;
					fd_src1 = open(file_src1, O_RDONLY, 0755);
					while(1){
						int p=0;
						int a;
						while((a=read(fd_src1,buffer,1)==1)){
							if(buffer[0]==' ')
								break;
							save[p++]=buffer[0];
							}
						save[p]='\0';
						if(save[0]=='\0')
							break;
						
						if(strcmp(save, key)==0){
							int k=0;
							while((a=read(fd_src1,buffer,1)==1)){
								if(buffer[0]=='\n')
									break;
								c[k++]=buffer[0];
								}
							c[k]='\0';
							int temp = atoi(c);
							value = (char*)malloc(sizeof(int));     
							*(int*)value = temp;
							close(fd_src1);
							free(b);
							free(ff);
							return value;
							}
						else{
							while((a=read(fd_src1,buffer,1)==1)){
								if(buffer[0]=='\n')
									break;
								}
							}
						}	
					free(b);
					free(ff);
					close(fd_src1);
					}	
				}
			}
		}
	return value;

}



                                                                                                                                                                                                                                                                                                                                                                                                     