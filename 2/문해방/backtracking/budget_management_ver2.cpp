#include <cstdio>
#include<algorithm>

using namespace std;

bool finished = false;
int n,b,maxBudget;
int a[20],arr[20];

bool is_a_solution(int k){
    return (k == n);
}

void construct_candidates (int k, int c[], int *n_can){
    c[0] = true;
    c[1] = false;
    *n_can = 2;
}

void process_solution (int k){
    int i,sum=0;
    for (i=1; i<=k; i++){
        if(a[i]==true)
            sum+=arr[i];
    }
    if(sum>b)
        return;
    maxBudget=max(maxBudget,sum);
}

void backtrack(int k){
    int c[100];
    int n_can;
    int i;

    if (is_a_solution(k))
        process_solution (k);
    else {
        k = k + 1;
        construct_candidates (k, c, &n_can);
        for (i=0;i<n_can;i++){
            a[k] = c[i];
            backtrack (k);
            if (finished) return;
        }
    }
}

int main()
{
    scanf("%d %d",&b,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    backtrack(0);
    printf("%d",maxBudget);
    return 0;
}

