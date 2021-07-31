#include<stdio.h>
int arr[25];
int pSum=0;
int cnt;
void countSubsetSum(int, int);
int main()
{
	int i,N,S;
	scanf("%d %d", &N, &S);
	for(i=1 ; i<=N ; i++)
		scanf("%d", &arr[i]);
    countSubsetSum(N,S);
    if(cnt==0)
        printf("There is no subset with sum %d",S);
    else
        printf("There is %d subsets with sum %d",cnt,S);
    return 0;
}

void countSubsetSum(int num,int sum)
{
	if(num == 0) return ;
	if(pSum + arr[num] == sum) cnt++;
	countSubsetSum(num-1,sum);
	pSum += arr[num];
	countSubsetSum(num-1,sum);
	pSum -= arr[num];
}
