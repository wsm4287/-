#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct A {
	char* name;
	int age;
	int rank;
	struct A *next;
} a;


int N;

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

a * get(a *first){
	char na[30];
	int ag;
	int ra;
	scanf("%s %d %d", na, &ag, &ra);
	a *temp = (a*)malloc(sizeof(a));
	temp ->name = (char*)malloc(sizeof(char)*(strlen(na)+1));
	int k;
	for(k=0; k<strlen(na); k++)
		temp->name[k]=na[k];
	temp->name[k]='\0';
	temp->age = ag;
	temp->rank = ra;
	
	a *cur= first;
	a *pre =NULL;
	if(cur==NULL){
		free(pre);
		free(cur);
		return temp;
	}
	else{
		while(cur->age>ag){
			if(cur->next==NULL)
				break;
			pre = cur;
			cur = cur->next;
		}
		if(cur->age>ag){
				temp ->next = cur->next;
				cur -> next =temp;
			}
		else if(cur->age==ag){
			if(compare(cur->name,na,0)==-1){
				while(cur->age==ag){
					if(cur->next==NULL||compare(cur->name,na,0)!=-1)
						break;
					pre = cur;
					cur = cur->next;
				}
				if(cur->age <ag){
					cur = pre;
				}
				temp ->next = cur->next;
				cur -> next =temp;
			}
			else if(compare(cur->name,na,0)==1){
				if(pre==NULL){
					free(pre);
					temp ->next = cur;
					return temp;
			}
				pre->next = temp;
				temp->next = cur;
			}
			else{
				if(cur->rank<ra){
					while(compare(cur->name,na,0)==0){
						if(cur->next==NULL||cur->rank>ra)
							break;
						pre = cur;
						cur = cur->next;
					}
					if(compare(cur->name,na,0)==1){
						cur = pre;
					}
					temp ->next = cur->next;
					cur -> next =temp;
				}
				else{
					if(pre==NULL){
						free(pre);
						temp ->next = cur;
						return temp;
			}
					pre->next = temp;
					temp->next =cur;
				}
			}
		}
		else{
			if(pre==NULL){
				free(pre);
				temp ->next = cur;
				return temp;
			}
			else{
				pre ->next = temp;
				temp ->next = cur;
			}
		}
	}
	return first;
}

int main() {
	scanf("%d",&N);
	a *x = NULL;
	int i;
	int k;
	for (i=0; i<N; i++){
		x=get(x);
	}
	for (i=0; i<N; i++){
		printf("%d %s %d\n", x->age, x->name, x->rank);
		x = x->next;
	}
	return 0;
}
