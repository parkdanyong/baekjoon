/*
    title: 경로 찾기
    tag: graph, graph search,  shortest path, Floyd-Warshall algorithm

*/


#include <stdio.h>
#include <stdlib.h>


#define INF 99999


int n;
int size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall(int* path) {
    int i, j, k;

    for (i = 0; i < size; i++) { // copy
        path[i] = arr[i];
    }
 
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) { // from
            for (j = 0; j < n; j++) { // to
                path[i*n + j] = min(path[i*n + j], path[i*n + k] + path[k*n + j]);
            }
        }
    }
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // size = n * n;
    // arr = (int*) calloc(size, sizeof(int));
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 0) arr[i] = INF;
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    size = n * n;
    arr = (int*) calloc(size, sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) arr[i] = INF;
    }


    // init
    int* path = (int*) malloc(sizeof(int)*size);
    floydWarshall(path);


    // answer
    for (int i = 0; i < size; i++) {
        if (path[i] != INF) printf("1 ");
        else printf("0 ");
        if ((i + 1) % n == 0) printf("\n");
    }


    free(arr);
    free(path);
    return 0;
}