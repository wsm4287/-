#include<cstdio>

int dp[40];
int n;
int num1,num2;
int decompose_dp(){

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    return dp[n];
}

int decompose_bt(int n){

    if(n==0 || n==1)    return 1;
    if(n==2) return 2;
    return decompose_bt(n-1)+decompose_bt(n-2)+decompose_bt(n-3);
}

int main(){

    scanf("%d",&n);
    int m=n;
    int num1=decompose_dp();
    printf("%d\n",num1);
    int num2=decompose_bt(m);
    printf("%d\n",num2);
    return 0;
}
