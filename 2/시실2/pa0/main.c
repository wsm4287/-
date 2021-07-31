
// Skeleton code for PA #0
//
// Computer Systems and Intelligence Laboratory
// Sungkyunkwan University
//
// Student Name  : 우승민
// Student ID No.: 2016310936
//------------------------------------------------------------------
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char buffer[1];


typedef struct word_list{
	char *a;
	int count;
	struct word_list *next;
}word;


word* insert(word *first, char *input,int len){
	word *temp = (word*)malloc(sizeof(word));
	word *cur = first;
	word *cur2 = '\0';
	temp -> a = (char*)malloc(sizeof(char)*(len+1));
	int k;
	temp -> count = 1;
	for(k=0; k<len; k++)
		temp -> a[k]= input[k];
	if(first ==NULL){
		first=temp;
		free(cur2);
		return first;
		}
	else{ 
	while(1){
		if(compare(cur->a, temp->a,0)==-1){
			while(compare(cur->a, temp->a,0)==-1){
				if(cur ->next ==NULL)
					break;  
				cur2 = cur;
				cur = cur -> next;
				}

			if(compare(cur->a, temp->a,0)==0){
				cur->count +=1;
				free(temp);
				return first;
				}

			if(compare(cur->a, temp->a,0)==1){
				cur2 -> next = temp;
				temp -> next = cur;	
				return first;
                       			}

                        		else{
                                      	cur ->next = temp;
				temp ->next = '\0';						
				return first;
				}
						
			}

		if(compare(cur->a, temp->a,0)==1){
				temp ->next = cur;
				free(cur2);
				return temp;
				}
		if(compare(cur->a, temp->a,0)==0){
				cur->count +=1;
				free(temp);
				return first;
				}

	
		}

	}
}


int compare(char *x1, char *y1, int k){
	if((x1[k]<=90)&&(y1[k]>90))
		{
			if(x1[k] +32 > y1[k])
				return 1;
			else
				return -1;	
	
		}
	if((x1[k]>90)&&(y1[k]<=90))
		{
			if(x1[k]  >= y1[k]+32)
				return 1;
			else 
				return -1;	
		}
	if((x1[k]==0)&&(y1[k]!=0))
		return -1;
	if((x1[k]!=0)&&(y1[k]==0))
		return 1;
	if((x1[k]==0)&&(y1[k]==0))
		return 0;
	if(x1[k] > y1[k])
		return 1;
	else if(x1[k] < y1[k])
		return -1;
	else{
		k++;
		compare(x1,y1,k);
	}	




}


void print_list(word *first){
	while(first != NULL)
	{
		char tmp[4];
		sprintf(tmp,"%d",first->count);
		strncat(first ->a, " ",1);
		strncat(first ->a, tmp, sizeof(tmp));
		write(1,first ->a, strlen(first->a));
		write(1,"\n",1);
		first = first->next;
	}

}

int main()
{
	int c;
	word* first=NULL;
	char *x = (char *)malloc(sizeof(char)*30);
	int i=0;
	int j=0;

	while((c = read(0,buffer,1))!= 0){
		if(i==0){
			if(((buffer[0]<='z')&&(buffer[0]>='a'))||((buffer[0]<='Z')&&(buffer[0]>='A'))){
				x[i] = buffer[0];
				i++;
			}
		}
		else{
			if(((buffer[0]<='z')&&(buffer[0]>='a'))||((buffer[0]<='Z')&&(buffer[0]>='A'))||(buffer[0]==39)||(buffer[0]=='-')){
				x[i] = buffer[0];
				i++;
			}
			else{
				while((x[i-1]==39)||(x[i-1]=='-')){
					x[i-1]='\0';
					i--;
				}
					first = insert(first,x,i);
					for(j=0; j<=i; j++)
						x[j]='\0';

				i=0;
			}
		}
	}
	if(x[0]>50)
		first = insert(first,x,i);

	print_list(first);

			



	
	return 0;
}
