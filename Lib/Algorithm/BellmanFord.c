/*
    Bellman-Ford
    O(ev)
    음수 가중치, 음수 사이클에서도 동작
*/


#define INF 1000


typedef struct Edge{
    int u, v, w;  // 출발 노드 u, 도착 노드 v, 가중치 w
}edge;


edge* edges;


int bellman_ford(int start, int n, int m) {
    int* dist = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    
    int u, v, w;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            u = edges[j].u;
            v = edges[j].v;
            w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < m; j++) {
        u = edges[j].u;
        v = edges[j].v;
        w = edges[j].w;
        if (dist[u] != INF && dist[u] + w < dist[v]) return 0;
    }
    return 1; 
}