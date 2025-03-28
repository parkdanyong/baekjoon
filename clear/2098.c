/*
    title: 외판원 순회
    tag: Traveling Salesman problem (TSP), dp, bit-masking
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define BITMASK 65536
#define CITY 16
#define INF 20000000



int N, size;
int* graph;
int dp[BITMASK][CITY];



int tsp(int visited, int cur) {
    if (visited == (1 << N) - 1) return graph[N*cur] ? graph[N*cur] : INF;
    else if (dp[visited][cur] != -1) return dp[visited][cur];


    int minCost = INF;
    for (int next = 0; next < N; next++) {
        if ((visited & (1 << next)) == 0 && graph[N*cur + next] != 0) {
            minCost = min(minCost, graph[N*cur + next] + tsp(visited | (1 << next), next));
        }
    }

    return dp[visited][cur] = minCost;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // size = N * N;
    // graph = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         fscanf(file, "%d", &graph[N*i + j]);
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    size = N * N;
    graph = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &graph[N*i + j]);
        }
    }


    // init
    memset(dp, -1, sizeof(dp));


    // answer
    int ans = 0;
    ans = tsp(1, 0);
    printf("%d\n", ans);


    free(graph);
    return 0;
}