#include<stdio.h>
#include<math.h>

#define MAX 100

int n, check[MAX];
double dot[MAX][2], min_d[MAX], result;

void input(){
    int i;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%lf %lf", &dot[i][0], &dot[i][1]);
    }
}

double distance(int a, int b){
    return sqrt( pow(dot[a][0] - dot[b][0], 2) + pow(dot[a][1] - dot[b][1], 2));
}

void solve(){
    int i, j, a;

    result = 0;
    for(i=0;i<n;i++)
        check[i] = 0;

    check[0]=1;
    for(i=1;i<n;i++)
        min_d[i] = distance(0, i);

    for(i=0; i< n -1; i++){
        a = -1;
        for(j=0;j<n;j++){
            if (check[j])
                continue;
            if (a == -1 || min_d[a] > min_d[j])
                a = j;
        }
        result += min_d[a];
        check[a] = 1;

        for(j=0;j<n;j++){
            if (check[j])
                continue;
            if (min_d[j] > distance(a, j))
                min_d[j] = distance(a, j);
        }
    }

}

int main(){
    input();
    solve();
    printf("%0.2lf\n", result);

    return 0;
}
