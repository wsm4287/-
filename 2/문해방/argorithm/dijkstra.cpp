#include<stdio.h>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define INF INT_MAX

int E, V, K;

struct uvw{
    int v;
    int w;
};

vector<uvw> vec[300001];

int dist[20001];

void dijkstra(){
    priority_queue<pair <int, int> > q;
    q.push(make_pair(0, K));

    while(!q.empty()){
        int now = q.top().second;
        int cost = -1*q.top().first;
        q.pop();

        if (dist[now] < cost){
            printf("[No Update]::Node %d:Current Cost:%d\n", now, cost);
            continue;
        }
        else{
            printf("[Update]::Node %d:Current Cost:%d\n", now, cost);
        }
        for(int k=0; k<vec[now].size();k++){
            int new_w = dist[now] + vec[now][k].w;
            int before_w = dist[vec[now][k].v];
            if (new_w < before_w){
                dist[vec[now][k].v]=new_w;
                q.push(make_pair(-1*new_w, vec[now][k].v));
                printf("[push]: (%d, %d)\n", -1*new_w, vec[now][k].v);
            }
        }
    }
}

int main(){
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for(int i=0; i<E; i++){
        int from;
        int to;
        int value;
        scanf("%d %d %d", &from, &to, &value);
        vec[from].push_back(uvw{to, value});
    }
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }
    dist[K] = 0;
    dijkstra();
    for (int i=1; i<=V; i++){
        if(dist[i]!=INF)
            printf("%d\n", dist[i]);
        else
            printf("INF\n");
    }
}
