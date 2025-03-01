/*
    title: 서강그라운드
    tag: graph, Floyd-Warshall
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 10000



int n, m, r, size;
int* items;
int* arr;


int max(int a, int b) {
    return a > b ? a : b;
}


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall() {
    for (int k = 1; k <= n; k++) { // path visiting node k
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                arr[i*(n+1) + j] =  min(arr[i*(n+1) + j], arr[i*(n+1) + k] + arr[k*(n+1) + j]);
            }
        }
    }
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &n, &m, &r);
    // items = (int*) calloc(n+1, sizeof(int));
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d", &items[i]);
    // }
    // size = (n+1) * (n+1);
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     if (i / (n+1) == i % (n+1)) arr[i] = 0;
    //     else arr[i] = INF;
    // }
    // int v1, v2, weight;
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d %d %d", &v1, &v2, &weight);
    //     arr[(n+1)*v1 + v2] = weight;
    //     arr[(n+1)*v2 + v1] = weight;
    // }
    // fclose(file); 


    // input
    scanf("%d %d %d", &n, &m, &r);
    items = (int*) calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &items[i]);
    }
    size = (n+1) * (n+1);
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        if (i / (n+1) == i % (n+1)) arr[i] = 0;
        else arr[i] = INF;
    }
    int v1, v2, weight;
    for (int i = 0; i < size; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        arr[(n+1)*v1 + v2] = weight;
        arr[(n+1)*v2 + v1] = weight;
    }



    // answer
    floydWarshall();
    int cmp = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[(n+1)*i + j] <= m) cmp += items[j];
        }
        ans = max(ans, cmp);
        cmp = 0;
    }
    printf("%d\n", ans);


    free(items);
    free(arr);
    return 0;
}