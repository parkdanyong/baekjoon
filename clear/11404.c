/*
    title: 플로이드
    tag: graph, shortest path, Floyd-Warshall
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 100000000


int n, bus, size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall() {
    for (int k = 1; k <= n; k++) { // path visiting node k
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                arr[(n+1)*i + j] =  min(arr[(n+1)*i + j], arr[(n+1)*i + k] + arr[(n+1)*k + j]);
            }
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // fscanf(file, "%d", &bus);
    // size = (n+1) * (n+1);
    // arr = (int*) malloc(sizeof(int)*size);
    // int v1, v2, weight;
    // for (int i = 0; i < size; i++) {
    //     arr[i] = INF;
    // }
    // for (int i = 0; i < bus; i++) {
    //     fscanf(file, "%d %d %d", &v1, &v2, &weight);
    //     arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], weight);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    scanf("%d", &bus);
    size = (n+1) * (n+1);
    arr = (int*) malloc(sizeof(int)*size);
    int v1, v2, weight;
    for (int i = 0; i < size; i++) {
        arr[i] = INF;
    }
    for (int i = 0; i < bus; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], weight);
    }


    // answer
    floydWarshall();
    for (int i = n+2; i < size; i++) {
        if (i % (n+1) == 0) printf("\n");
        else if ((int) i / (n+1) == i % (n+1) || arr[i] == INF) printf("0 ");
        else printf("%d ", arr[i]);
    }


    free(arr);
    return 0;
}