#include <cstdio>
#include <algorithm>

using namespace std;

int c[22];
int budgetManagement(int k,int b, int n)
{
    if(k==n) return 0;
    if(b<c[k]) return budgetManagement(k+1,b,n);
    return max(c[k]+budgetManagement(k+1,b-c[k],n),budgetManagement(k+1,b,n));
}
int main()
{
    int budget,num;
    scanf("%d",&budget);
    scanf("%d",&num);
    for(int i=0;i<num;i++) scanf("%d",&c[i]);
    printf("%d",budgetManagement(0,budget,num));
}
