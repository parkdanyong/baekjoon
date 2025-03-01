/*
    title: 특정한 최단 경로
    tag: graph, shortest path, dijkstra


    All cases come down to two things:
    s - v1 - v2 - e
    s - v2 - v1 - e

    Simple instacne
    s - e - v1 - e - v2 - e
    s - (e - v1) - (e - v2) - e
    s - v1 - v2 - e
    
    s - e - v1 == s - v1
    v1 - e - v2 == v1 - v2

    
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 2400000


int n, e, size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


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
    int* sptSet = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = arr[(n+1)*start + i];
        sptSet[i] = 0;
    }
    dist[start] = 0;
    sptSet[start] = 1;

    int u;
    for (int i = 1; i <= n; i++) {
        u = minDistance(dist, sptSet);
        if (u == 0) break;
        sptSet[u] = 1;

        for (int v = 1; v <= n; v++) {
            if (!sptSet[v] && dist[u] + arr[(n+1)*u + v] < dist[v]) {
                dist[v] = dist[u] + arr[(n+1)*u + v];
            }
        }
    }
    
    int val = dist[end];
    free(dist);
    free(sptSet);
    return val;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &e);
    // size = (n + 1) * (n + 1);
    // arr = (int*) malloc(sizeof(int)*size);
    // int v1, v2, weight;
    // for (int i = 0; i < size; i++) {
    //     arr[i] = INF;
    // }
    // for (int i = 0; i < e; i++) {
    //     fscanf(file, "%d %d %d", &v1, &v2, &weight);
    //     arr[(n+1)*v1 + v2] = weight;
    //     arr[(n+1)*v2 + v1] = weight;
    // }
    // fscanf(file, "%d %d", &v1, &v2);
    // fclose(file);


    // input
    scanf("%d %d", &n, &e);
    size = (n + 1) * (n + 1);
    arr = (int*) malloc(sizeof(int)*size);
    int v1, v2, weight;
    for (int i = 0; i < size; i++) {
        arr[i] = INF;
    }
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        arr[(n+1)*v1 + v2] = weight;
        arr[(n+1)*v2 + v1] = weight;
    }
    scanf("%d %d", &v1, &v2);


    // init
    int v1_v2 = dijkstra(v1, v2);
    int start_v1 = dijkstra(1, v1);
    int start_v2 = dijkstra(1, v2);
    int v1_end = dijkstra(v1, n);
    int v2_end = dijkstra(v2, n);


    // answer
    int ans = min(start_v1 + v2_end, start_v2 + v1_end) + v1_v2;
    if (ans >= INF) printf("-1\n");
    else printf("%d\n", ans);
    

    free(arr);
    return 0;
}