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

int t;

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
	return db;
}

void db_close(db_t *db)
{
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

void db_put(db_t *db, char *key, int key_len,
			char *val, int val_len)
{	
	db_t *temp = (db_t *)malloc(sizeof(db_t));
	temp -> word = (char*)malloc(sizeof(char)*(key_len+1));
	int k;
	temp -> count=1;
	temp -> next = NULL;
	for(k=0; k<key_len; k++)
		temp -> word[k]= key[k];
	int x= key[0];
	db_t *cur = &db[x];
	if(*(int*)val==1){
		if(db[x].word==0){
			db[x].word=temp->word;
			db[x].count=temp->count;
			db[x].next=NULL;	
			free(temp);
			return ;
			}
		else{
			while(1){
				if(cur -> next == NULL)
					break;
				cur = cur ->next;
				}
			cur -> next = temp;
			}
		}
	else{ 
		while(1){
			if(strcmp(cur->word,key)!=0)
				cur = cur ->next;
			else
				break;
			}
		cur->count = cur->count+1;
	}

}
/* Returns NULL if not found. A malloc()ed array otherwise.
 * Stores the length of the array in *vallen */
char *db_get(db_t *db, char *key, int key_len,
			int *val_len)
{
	char *value = NULL;
	int x;
	x=key[0];
	db_t * cur = &db[x];
	if(db[x].word==NULL) return value;
	while(1){
		if(cur->next == NULL){
			break;
		}
		if(strcmp(key,cur->word)!=0)
			cur = cur->next;
		else
			break;
	}


	if(strcmp(key,cur->word)==0){
		value = (char*)malloc(sizeof(int));     
		*(int*)value = cur -> count;
		
		
		}
	else{
		if(cur->next == NULL)
			return value;
	}
	return value;

}




