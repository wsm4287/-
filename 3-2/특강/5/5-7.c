#include <stdio.h>
 
typedef struct{
    int x, y, time;
}QUE;
 
QUE que[5000000]; 
int N, M;
int R, C, S, K;
int sol;
int wp, rp;
 
int dx[]= { -1, 1, 2, 2, 1, -1, -2, -2};
int dy[]= {-2, -2, -1, 1, 2, 2, 1, -1};
int check[110][110];
 
int bfs(){
    que[wp++] = (QUE){C, R, 0};     
    while(rp < wp){
        QUE q = que[rp++];
        if(q.x == K && q.y == S) return q.time;
        for(int i=0; i<8; i++){
            int nx = q.x + dx[i];
            int ny = q.y + dy[i];
            if(check[ny][nx]) continue
            if(nx <1 || ny <1 || nx >M || ny > N) continue;
            check[ny][nx];
            que[wp++] = (QUE){nx, ny, q.time+1};
        }
    }
    return -1;
}
 
  
int main(void)
{
  
      // 입력받는 부분
      scanf("%d %d", &N, &M);
      scanf("%d %d %d %d", &R, &C, &S, &K);
  
      // 여기서부터 작성
 
      sol = bfs();
  
      // 출력하는 부분
      printf("%d", sol);
  
      return 0;
}