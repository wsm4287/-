#include<cstdio>

#define MAX 200

int n, l, a, b, graph[MAX][MAX];
int colorable=1;
int color[MAX];

void dfs(int node, int c){

    color[node]=c;
    for(int i=0;i<n && colorable;i++){
        if(graph[node][i]==0)
            continue;
        if(!color[i])
            dfs(i,c%2+1);   //if c==1 dfs(i,2) else dfs(i,1)
        else{
            if(color[i]==c){
                colorable=0;
                return;
            }
        }
    }
}

int main(){

    scanf("%d%d",&l,&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        graph[a][b]=graph[b][a]=1;
    }
    dfs(0,1);
    if(colorable)
        printf("COLORABLE\n");
    else
        printf("NOT COLORABLE\n");
    return 0;
}
