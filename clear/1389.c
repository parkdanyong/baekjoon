/*
    title: 케빈 베이컨의 6단계 법칙
    tag: graph, BFS, shortest path, Floyd-Warshall algorithm

    matrix
    cols = from
    rows = to

*/




#include <stdio.h>
#include <stdlib.h>


#define INF 99999

int n, m;
int size;
int* matrix;


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall(int* dis) {
    for (int i = 0; i < size; i++) { // copy
        dis[i] = matrix[i];
    }


    for (int k = 1; k <= n; k++) { // path visiting node k
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                dis[i*(n+1) + j] =  min(dis[i*(n+1) + j], dis[k*(n+1) + j] + dis[i*(n+1) + k]);
            }
        }
    }
}




int main() { 
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // size = (n+1)*(n+1);
    // matrix = (int*) calloc(size, sizeof(int));
    // int a, b;
    // for (int i = 0; i < size; i++) {
    //     matrix[i] = INF;
    // }
    // for (int i = 1; i <= m; i++) {
    //     fscanf(file, "%d %d", &a, &b);
    //     matrix[b*(n+1) + a] = 1; // a -> b
    //     matrix[a*(n+1) + b] = 1; // b -> a
    // }
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    size = (n+1)*(n+1);
    matrix = (int*) calloc(size, sizeof(int));
    int a, b;
    for (int i = 0; i < size; i++) {
        matrix[i] = INF;
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        matrix[b*(n+1) + a] = 1; // a -> b
        matrix[a*(n+1) + b] = 1; // b -> a
    }


    // init
    int* dis = (int*) malloc(sizeof(int)*size);
    floydWarshall(dis);


    // answer
    int cmp = 0;
    int minDis = INF;
    int ans = 0;
    for (int i = 1; i <= n; i++) { // col
        cmp = 0;
        for (int j = 1; j <= n; j++) { // row
            cmp += dis[j*(n+1) + i];
        }
        if (cmp < minDis) {
            minDis = cmp;
            ans = i;
        }
    }
    printf("%d\n", ans);



    free(matrix);
    free(dis);
    return 0;
}