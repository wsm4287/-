#include <stdio.h>
 
int R, G, B, N;
int a[20][3];
int ans = 99999;
 
void dfs(int k, int n, int r, int g, int b){
 
    if(k>N) return;
    if(n > ans) return;
    if(n){
        if(r == n*R && g == n*G && b == n*B){
            if(ans > n ) ans = n;
        } 
    }   
    dfs(k+1, n+1, r + a[k][0], g + a[k][1], b + a[k][2]);
    dfs(k+1, n, r, g, b);
 
}
 
 
 
int main(){
    scanf("%d %d %d %d", &R, &G, &B, &N);
    for(int i=0; i<N; i++) scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    dfs(0,0,0,0,0);   
    if(ans != 99999) printf("%d", ans);
    else printf("-1");
 
}

