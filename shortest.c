#include <stdio.h>
#include <limits.h>
#define V 4

int min(int dist[], int visited[]){
    int m = INT_MAX, index;
    for(int i=0;i<V;i++)
        if(!visited[i] && dist[i]<m){
            m = dist[i];
            index = i;
        }
    return index;
}

void dijkstra(int g[V][V], int s){
    int dist[V], visited[V]={0};

    for(int i=0;i<V;i++) dist[i]=INT_MAX;
    dist[s]=0;

    for(int i=0;i<V-1;i++){
        int u = min(dist,visited);
        visited[u]=1;

        for(int v=0;v<V;v++)
            if(!visited[v] && g[u][v] && dist[u]+g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
    }

    for(int i=0;i<V;i++)
        printf("%d -> %d\n", i, dist[i]);
}

int main(){
    int g[V][V] = {
        {0,1,4,0},
        {1,0,2,5},
        {4,2,0,1},
        {0,5,1,0}
    };

    dijkstra(g,0);
}