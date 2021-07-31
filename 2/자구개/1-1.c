#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char a[100];
char b[100];
char a1[100];
char b1[100];


int add(char *x, char *y, char *d)
{		
		int k=0;
		int i=0;
		int j=0;
		char s=0;
		while((x[i]!=0)&&(y[j]!=0)){
			d[k]=x[i]+y[j]-48+s;
			if(d[k]>57){
				s= 1;
			  d[k]= d[k]-10;
			}
			else
				s=0;
			i++;
			j++;
			k++;
		}
		while((x[i]==0)&&(y[j]!=0)){
			d[k]=y[j]+s;
			if(d[k]>57){
				s= 1;
			  d[k]= d[k]-10;
			}
			else
				s=0;
			j++;
			k++;
		}
		while((x[i]!=0)&&(y[j]==0)){
			d[k]=x[i]+s;
			if(d[k]>57){
				s= 1;
			  d[k]= d[k]-10;
			}
			else
				s=0;
			i++;
			k++;
			
		}
		
		if(s!=0){
			d[k]=s+48;
	  }
		
	return k;

}


void mul(char *x, char *y, char *d, int i, int j)
{
	int q=0;
	int p=0;
	int k=0;
	int t=0;
	char *a2 = (char *)malloc(sizeof(char)*(i*j+1));
	for(k=0; k<i; k++)
		a2[k]=x[k];
	a2[i]='\0';
	
	if((j==1)&&(y="0")){
		printf("0");
		return;
	}
	
	while(y[p]!=0){	
			while(y[p]-48>0){
				q=add(a2,d,d);
				y[p]=y[p]-1;
			}
		
		p++;
		d = (char *)realloc(d,sizeof(char)*(i+2+p));
		d[i+p]='0';
		d[i+p+1]='\0';
		for(k=i+p-1; k>=p; k--)
			a2[k]=a2[k-1];
		for(k=p-1; k>=0; k--)
			a2[k]='0';
	}	
	
		for(t=q-1; t>=0; t--)
			printf("%c", d[t]);
			
}



int main() {
	char op;

	int i=0;
	int j=0;
	scanf("%c", &op);
	char c;

	scanf("%s %s", &a, &b);

	
	i = strlen(a);
	j = strlen(b);
	
	int k;
	for(k=0; k<i; k++)
		a1[k]=a[i-k-1];
	for(k=0; k<j; k++)
		b1[k]=b[j-k-1];
	
	k=0;

	a1[i]='\0';
	b1[j]='\0';
	

	if(op=='+'){
		
		char *d = (char *)malloc(sizeof(char)*(i+j+1));
	
		k=add(a1,b1,d);
		
		for(j=k; j>=0; j--){
			if(d[j]!=0)
				printf("%c",d[j]);
		}
	
		
	}
	
	else{
		char *d = (char *)malloc(sizeof(char)*(i+1));
		for(k=0; k<=i; k++)
			d[k]='0';
		
		mul(a1,b1,d,i,j);
		
		
	}
	
	
	return 0;
	
	
		

}