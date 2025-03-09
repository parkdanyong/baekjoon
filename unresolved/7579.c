/*
    title: 앱
    tag: dp, Knapsack Problem
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Item {
    int W;
    int V;
}Item;


int N, M;
Item* arr;


int knapsack(int totalCost) {
    int* bag = (int*) calloc(totalCost+1, sizeof(int));

    for (int i = 0; i < N; i++) {
        for (int j = totalCost; j >= arr[i].W; j--) { 
            bag[j] = (bag[j] > bag[j - arr[i].W] + arr[i].V) ? bag[j] : (bag[j - arr[i].W] + arr[i].V);
        }
    }
    int result = 0;
    for (int j = 0; j <= totalCost; j++) {
        if (bag[j] >= M) { 
            result = j;
            break;
        }
    }
    
    free(bag);
    return result;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &M);
    // arr = (Item*) malloc(sizeof(Item)*N);
    // int totalCost = 0;
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i].V);
    // }
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i].W);
    //     totalCost += arr[i].W;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &M);
    arr = (Item*) malloc(sizeof(Item)*N);
    int totalCost = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i].V);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i].W);
        totalCost += arr[i].W;
    }


    // answer
    int ans = knapsack(totalCost);
    printf("%d\n", ans);


    free(arr);
    return 0;
}