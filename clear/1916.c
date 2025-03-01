/*
    title: 최소비용 구하기
    tag: graph, shortest path, dijkstra


    arr:
        rows: from
        cols: to
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 100000000


int n, m, size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


int minDistance(int* dist, int* sptSet) {
    int minDist = INF;
    int minIndex;
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



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // size = (n + 1) * (n + 1);
    // arr = (int*) malloc(sizeof(int)*size);
    // int to, from, cost;
    // for (int i = 0; i < size; i++) {
    //     arr[i] = INF;
    // }
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d %d %d", &from, &to, &cost);
    //     arr[(n+1)*from + to] = min(arr[(n+1)*from + to], cost);
    // }
    // fscanf(file, "%d %d", &from ,&to);
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    size = (n + 1) * (n + 1);
    arr = (int*) malloc(sizeof(int)*size);
    int to, from, cost;
    for (int i = 0; i < size; i++) {
        arr[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &from, &to, &cost);
        arr[(n+1)*from + to] = min(arr[(n+1)*from + to], cost);
    }
    scanf("%d %d", &from ,&to);


    // answer
    int ans = dijkstra(from, to);
    printf("%d\n", ans);


    free(arr);
    return 0;
}