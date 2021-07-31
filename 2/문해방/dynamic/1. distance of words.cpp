#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char arr1[50], arr2[50];
int dp[50][50];
int len1,len2;
int dist,dist2;

int distance_of_words_dp(){

    for(int i=1;i<=len1;i++)
        dp[i][0]=i;
    for(int j=1;j<=len2;j++)
        dp[0][j]=j;
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(arr1[i-1]==arr2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(dp[i][j-1]+1,min(dp[i-1][j]+1,dp[i-1][j-1]+1));
        }
    }
    return dp[len1-1][len2-1];
}

int distance_of_words_bt(int len1,int len2){
    if(len1==0) return len2;
    if(len2==0) return len1;
    if(arr1[len1-1]==arr2[len2-1])  return distance_of_words_bt(len1-1,len2-1);
    return min(distance_of_words_bt(len1,len2-1)+1,min(distance_of_words_bt(len1-1,len2)+1,distance_of_words_bt(len1-1,len2-1)+1));
}

int main(){

    gets(arr1);
    gets(arr2);
    len1=strlen(arr1);
    len2=strlen(arr2);
    int l1=len1,l2=len2;
    dist=distance_of_words_dp();
    printf("%d\n",dist);
    dist2=distance_of_words_bt(l1,l2);
    printf("%d\n",dist2);
    return 0;
}
