#include <stdio.h>
 
int R, G, Y, M;
 
int a[15][3];
 
int check[15];
 
int max;
 
void dfs(int k, int x, int r, int g, int y){
 
    if(max == 3*M) return;
    if(r < 0 || g < 0 || y < 0){
        return;
    }   
    if(k==M){
        if(max < x) max = x;
        return;
    }
    if(check[k] <2){
        check[k]++;
        dfs(k, x+1, r -a [k][0], g - a[k][1], y - a[k][2]);
        check[k]--;
    }
    else if(check[k] ==2){
        check[k]++;
        dfs(k+1, x+1, r -a [k][0], g - a[k][1], y - a[k][2]);
        check[k]--;
    }
    dfs(k+1, x, r, g, y);
    return;
 
}
 
 
int main(){
    scanf("%d %d %d %d", &M, &R, &G, &Y);
    for(int i=0; i<M; i++){
        scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
    }
    dfs(0,0,R,G,Y);
    printf("%d", max);
 
}