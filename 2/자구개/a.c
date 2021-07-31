#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct word_list{
	char *a;
	int count;
	struct word_list *next;
}word;

char c[50];

char w[1000][50];
int x[1000];
int y[1000];



int compare(char *x1, char *y1, int k){
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


word* insert(word *first, char *input,int len, int i){
	word *temp = (word*)malloc(sizeof(word));
	word *cur = first;
	word *cur2 = '\0';
	temp -> a = (char*)malloc(sizeof(char)*(len+1));
	int k;
	int j;
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

void print_list(word *first){
	while(first != NULL)
	{
		printf("%s\n",first ->a);
		first = first->next;
	}

}

int main()
{
	
	word* first=NULL;
	int i=0;
	int j=0;
	int t;
	scanf("%d", &t);
	getchar();
	
	for(i=0; i<t; i++){
		scanf("%s", c);
		first = insert(first,c,strlen(c),i);
	}

	i=0;
	while(first!=NULL){
		for(j=0; j<strlen(first->a); j++)
			w[i][j]=first->a[j];
		
		x[i]= first->count;
		first = first ->next;
		i++;
	}
	int max;
	int k;
	
	int q=0;
	for(j=0; j<i; j++){
		for(k=i-1; k>=0; k--){
			if(y[k]==0)
				max = k;
		}
		for(k=0; k<i; k++){
			if(x[k]> x[max]){
				if(y[k]==0)
					max = k;
			}
		}
		if(y[max]==0){
			printf("%s\n",w[max]);
			y[max]=1;
		}
	}
	
	
}


