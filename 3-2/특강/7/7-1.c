#include <stdio.h>
 
int N, K;
int a[1500][50];
int A, B;
int b[1500];
int end;
int check[1500];
int que[1010];
int rp, wp;
 
 
int add(int p, int q){
    int t1 = 0;
    int t2 = 0;
    for(int i=0; i<K; i++){
        t1 += a[p][i];
        t2 += a[q][i];
    }
 
    if(t1 > t2) return t1-t2;
    else return t2-t1;
 
}
/*
void dfs(int k, int n){
    if(end) return;
    b[n] = k;
    if(n > N) return;
    if(k == B){
        end = n; 
        return; 
    }
    for(int i=1; i<=N; i++){
        if(check[i]) continue;
        if(add(k,i)==1){
            check[i]=1;
            dfs(i, n+1);
            check[i]=0;
        }
 
    }
     
 
}
 
 
 
int main(){
 
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++){
        for(int j=0; j<K; j++) scanf("%1d", &a[i][j]);
    }
    scanf("%d %d", &A, &B);
 
    check[1]=1;
    dfs(A,0);
    if(end){
        for(int i=0; i<=end; i++) printf("%d ", b[i]);
    }
    else printf("-1");
}
*/
 
int bfs(){
    int no, q;
    que[wp++] = A;
    check[A] = 1;
    b[A] = 0;
    while(rp < wp){
        q = que[rp++];
        for(int i=1; i<=N; i++){
            if(check[i]) continue;
            if(add(q,i) ==1){
                check[i]=1;
                b[i] = q;
                que[wp++] = i;
                if(i == B) return 1;
            }
 
        }
 
    }
 
    return -1;
 
}
 
void print(int n){
    if(n==0) return;
    print(b[n]);
    printf("%d ", n);
}
 
int main(){
 
    scanf("%d %d", &N, &K);
    for(int i=1; i<=N; i++){
        for(int j=0; j<K; j++) scanf("%1d", &a[i][j]);
    }
    scanf("%d %d", &A, &B);
 
    if(bfs()==1) print(B);
    else printf("-1");
}