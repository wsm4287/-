#include <stdio.h>
 
int H, W, N;
char a[1100][1100];
typedef struct QUE{
    int x, y, cnt;
 
}que;
 
que q[1000000];
int rp, wp;
int x1, y1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int check[1100][1100];
int cnt;
 
que bfs(que s, int n){
    que qq;
    rp = wp =0;
    q[wp++] = s;
    check[s.y][s.x] = n;
    while(rp < wp){
        qq = q[rp++];
        for(int k=0; k<4; k++){
            int nx = qq.x + dx[k];
            int ny = qq.y + dy[k];
            if(nx < 0 || ny < 0 || nx >= W || ny >= H) continue;
            if(check[ny][nx] == n) continue;
            if(a[ny][nx] == 'X') continue;
            if(a[ny][nx] == n + '0'){
                return (que) { nx, ny, qq.cnt+1};
            }
            check[ny][nx] = n;
            q[wp++] = (que) { nx, ny, qq.cnt+1};
        }
 
    }
 
}
 
que find(){
    int i,j;
    for(i=0; i<H; i++){
        for(j=0; j<W; j++){
            if(a[i][j] =='S') return (que) { j,i,0};
        }
    }
}
 
int main(){
 
    scanf("%d %d %d", &H, &W, &N);
    for(int i=0; i<H; i++){
            scanf("%s", a[i]);
    }
    que pos;
    pos = find();
    for(int i=1; i<=N; i++) pos =  bfs(pos, i);
    printf("%d", pos.cnt);
    return 0;
 
}
