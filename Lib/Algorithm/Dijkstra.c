/*
    O(n^2)
*/

#define INF 10000000

int n;
int* arr;

int minDistance(int* dist, int* sptSet) {
    int minDist = INF;
    int minIndex = 0;
    for (int i = 1; i <= n; i++) {
        if (!sptSet[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}


int dijkstra(int start, int end) {
    int* dist = (int*) malloc(sizeof(int)*(n+1));
    int* path = (int*) calloc(n+1, sizeof(int));
    int* sptSet = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = arr[(n+1)*start + i];
        sptSet[i] = 0;
    }
    sptSet[start] = 1;
    dist[start] = 0;

    int u;
    for (int i = 1; i < n; i++) {
        u = minDistance(dist, sptSet);
        if (u == 0) break;
        sptSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!sptSet[v] && dist[u] + arr[(n+1)*u + v] < dist[v]) {
                dist[v] = dist[u] + arr[(n+1)*u + v];
                path[v] = u;
            }
        }
    }

    int val = dist[end];
    free(dist);
    free(sptSet);
    free(path);
    return val;
}