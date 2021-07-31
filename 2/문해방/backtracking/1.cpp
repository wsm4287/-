#include <cstdio>
#define Max 100
using namespace std;

int a[Max];
int x[Max];
int N;
int sum[Max];
int b;
int t;
int menu;
int target;
int above=5555;

int is(int *a,int k,int n)
{
	return(k==n);
}

void process(int *a, int k, int n)
{
    int s=0;
	int i;
	for(i=1; i<=n; i++){
		if(x[i] ==1)
			s += a[i];
		}
    if(menu ==1){
        for(i=1; i<=n; i++){
            if(x[i] == 1)
                printf("%d ", a[i]);
        }
        printf("\n");
    }
    else if(menu==2){
        if(s == target){
            for(i=1; i<=n; i++){
                  if(x[i] == 1)
                        printf("%d ", a[i]);
            }
        }
    }
    else if(menu ==3){
        if(target < s){
            if(above > s)
                above = s;
        }
    }

}

void candidate(int *a, int k, int n, int *c, int *nc)
{
	*nc =2;
	c[0] = 0;
	c[1] =1;
}

void backtrack(int *a, int k, int n)
{
	int c[2];
	int nc;
	int i;
	if(is(a,k,n))
		process(a,k,n);
	else{
		k++;
		candidate(a,k,n,c,&nc);
		for(i=0; i<nc; i++){
			x[k] = c[i];
			backtrack(a,k,n);
			}
		}

}


int main()
{
	scanf("%d", &N);
	int i;
	for(i=0; i<N; i++)
		scanf("%d", &a[i+1]);

    scanf("%d", &menu);
    if(menu!= 1)
        scanf("%d", &target);
	backtrack(a,0,N);
	i=2;
	int j;
	int Min;
	if(menu==3)
        printf("%d", above);

	for(i=1; i<=t; i++){
		for(j=1; j<=t; j++){
			if((i!=j)&&(sum[i] == sum[j]))
				sum[j]=0;
			}
		}

	for(i=1; i<=t; i++){
		Min=i;
		for(j=i+1; j<=t; j++)
			if(sum[Min]>sum[j]) Min =j;
		s = sum[i];
		sum[i] = sum[Min];
		sum[Min] = s;
		}

	for(i=1; i<=t; i++)
		if(sum[i]!=0)	printf("%d ", sum[i]);*/




}

