/*
    title: 평범한 배낭
    tag: dp, Knapsack Problem
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Stuff {
    int W;
    int V;
}stuff;


int max(int a, int b) {
    return a > b ? a : b;
}


int compare(const void* arg1, const void* arg2) {
    stuff a = *(stuff*) arg1;
    stuff b = *(stuff*) arg2;
    int cmp = a.W - b.W;
    if (cmp == 0) return a.V - b.V;
    else return cmp;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, k;
    // fscanf(file, "%d %d", &n, &k);
    // stuff* arr = (stuff*) malloc(sizeof(stuff)*(n+1));
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d %d", &arr[i].W, &arr[i].V);
    // }
    // fclose(file);


    // input
    int n, k;
    scanf("%d %d", &n, &k);
    stuff* arr = (stuff*) malloc(sizeof(stuff)*(n+1));
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &arr[i].W, &arr[i].V);
    }


    // init
    arr[0].W = 0;
    arr[0].V = 0;
    qsort(arr, n+1, sizeof(stuff), compare);
    int* bag = (int*) calloc((n+1)*(k+1), sizeof(int));
    

    // answer
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= k; w++) {
            if (w < arr[i].W) bag[(k+1)*i + w] = bag[(k+1)*(i-1) + w];
            else bag[(k+1)*i + w] = max(bag[(k+1)*(i-1) + w], bag[(k+1)*(i-1) + (w - arr[i].W)] + arr[i].V);
        }
    }
    printf("%d\n", bag[(k+1)*n + k]);


    free(arr);
    free(bag);
    return 0;
}