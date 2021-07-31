#include<cstdio>
#include<cstring>
#include<algorithm>
#include <ctime>

using namespace std;

char arr1[30], arr2[30];
char lcs[30];
int dp[30][30];
int len1,len2;
int dist,idx;

int lcs_len(){

    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(arr1[i-1]==arr2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[len1][len2];
}

void find_lcs(int m, int n){

    if(m==0 || n==0){
        int i=0;
        int j=idx-1;
        while(i<j){
            char temp=lcs[i];
            lcs[i]=lcs[j];
            lcs[j]=temp;
            i++;
            j--;
        }
        lcs[idx]='\0';
        return;
    }
    if(dp[m][n]>dp[m-1][n-1] && dp[m][n]>dp[m][n-1] && dp[m][n]>dp[m-1][n]){
        lcs[idx++]=arr1[m-1];
        find_lcs(m-1,n-1);
    }
    else if(dp[m][n]>dp[m-1][n] && dp[m][n]==dp[m][n-1])
        find_lcs(m,n-1);
    else
        find_lcs(m-1,n);
}
int main(){

    clock_t s,e;
    gets(arr1);
    gets(arr2);
    len1=strlen(arr1);
    len2=strlen(arr2);
    s=clock();
    dist=lcs_len();
    find_lcs(len1,len2);
    e=clock();
    printf("The length of the lcs : %d\n",dist);
    printf("The lcs : %s\n",lcs);
    printf("Execution Time: %lf",(double)(e-s)/CLK_TCK);
    return 0;
}
