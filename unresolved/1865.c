/*
    title: 웜홀
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 251001
#define INF 10000000


int T, n, m, w, size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall() {
    for (int k = 1; k <= n; k++) { 
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                arr[i*(n+1) + j] =  min(arr[i*(n+1) + j], arr[i*(n+1) + k] + arr[k*(n+1) + j]);
            }
        }
    }
}


void initArr() {
    for(int i = 0; i < MAX_SIZE; i++) {
        arr[i] = INF;
    }
}


void isPosible() {
    for (int i = 1; i <= n; i++) {
        if (arr[(n+1)*i + i] < 0) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}


int main() {
    FILE* file = fopen("inputFile.txt", "r");
    fscanf(file, "%d", &T);
    arr = (int*) malloc(sizeof(int)*MAX_SIZE);
    int v1, v2, weight;
    for (int i = 0; i < T; i++) {
        initArr();
        fscanf(file, "%d %d %d", &n, &m, &w);
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d %d %d", &v1, &v2, &weight);
            arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], weight);
            arr[(n+1)*v2 + v1] = min(arr[(n+1)*v2 + v1], weight);
        }
        for (int j = 0; j < w; j++) {
            fscanf(file, "%d %d %d", &v1, &v2, &weight);
            arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], -weight);
        }

        floydWarshall();
        isPosible();
    }
    fclose(file);


    // input
    // scanf("%d", &T);
    // arr = (int*) malloc(sizeof(int)*MAX_SIZE);
    // int v1, v2, weight;
    // for (int i = 0; i < T; i++) {
    //     initArr();
    //     scanf("%d %d %d", &n, &m, &w);
    //     for (int j = 0; j < m; j++) {
    //         scanf("%d %d %d", &v1, &v2, &weight);
    //         arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], weight);
    //         arr[(n+1)*v2 + v1] = min(arr[(n+1)*v2 + v1], weight);
    //     }
    //     for (int j = 0; j < w; j++) {
    //         scanf("%d %d %d", &v1, &v2, &weight);
    //         arr[(n+1)*v1 + v2] = min(arr[(n+1)*v1 + v2], -weight);
    //     }

    //     floydWarshall();
    //     isPosible();
    // }


    free(arr);
    return 0;
}