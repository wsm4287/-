#include<stdio.h>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

#define INF INT_MAX

int E, V, K, S, D;

struct uvw{
    int v;
    int w;
};

vector<uvw> vec[300001];

int dist[20001];
int total_dist;

void dijkstra(int start){
    priority_queue<pair <int, int> > q;
    q.push(make_pair(0, start));

    while(!q.empty()){
        int now = q.top().second;
        int cost = -1*q.top().first;
        q.pop();

        if (dist[now] < cost){
            //printf("[No Update]::Node %d:Current Cost:%d\n", now, cost);
            continue;
        }
        else{
            //printf("[Update]::Node %d:Current Cost:%d\n", now, cost);
        }
        for(int k=0; k<vec[now].size();k++){
            int new_w = dist[now] + vec[now][k].w;
            int before_w = dist[vec[now][k].v];
            if (new_w < before_w){
                dist[vec[now][k].v]=new_w;
                q.push(make_pair(-1*new_w, vec[now][k].v));
                //printf("[push]: (%d, %d)\n", -1*new_w, vec[now][k].v);
            }
        }
    }
}

int main(){
    /* Input Information */
    //printf("Input # of Node and Route Cost: ");
    scanf("%d %d", &V, &E);
    //printf("Input Start, Stops, Destination Points: ");
    scanf("%d %d %d", &K, &S, &D);
    //printf("Input Path and Cost\n");
    for(int i=0; i<E; i++){
        int from;
        int to;
        int value;
        scanf("%d %d %d", &from, &to, &value);
        vec[from].push_back(uvw{to, value});
    }

    /* Initialization */
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }

    /* From Star To Stops */
    dist[K] = 0;
    dijkstra(K);

    if (dist[S] != INF){
        total_dist = dist[S];
        printf("[Output]::Cost1::From Start To Stops: %d\n", dist[S]);
    }
    else{
        total_dist = INF;
        printf("[Output]::Cost1::From Start To Stops: INF\n");
    }

    /* Initialization */
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }

    /* From Stops To Destination */
    dist[S] = 0;
    dijkstra(S);

    if (dist[D] != INF){
        if (total_dist != INF)
            total_dist += dist[D];
        printf("[Output]::Cost2::From Stops To Destination: %d\n", dist[D]);
    }
    else{
        total_dist = INF;
        printf("[Output]::Cost2::From Stops To Destination: INF\n");
    }

    /* Total Cost */
    if (total_dist != INF)
        printf("[Output]::TotalCost: %d\n", total_dist);
    else
        printf("[Output]::TotalCost: INF\n");
}
