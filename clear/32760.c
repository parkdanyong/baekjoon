/*
    title: Nothing Everything
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int v1;
    int v2;
}Pair;



int N, M;
Pair* arr;


int compare(const void* arg1, const void* arg2) {
    Pair* a = (Pair*) arg1;
    Pair* b = (Pair*) arg2;
    int cmp = a->v1 - b->v1;
    if (cmp == 0) cmp = a->v2 - b->v2;
    return cmp;
}


int upperBound(int n, Pair* arr, int len) {
    int low = -1;
    int high = len;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (arr[mid].v1 <= n) low = mid;
        else high = mid;
    }
    return high;
}


int lowerBound(int n, Pair* arr, int len) {
    int low = -1;
    int high = len;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (n <= arr[mid].v1) high = mid;
        else low = mid;
    }
    return low;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &M);
    // arr = (Pair*) malloc(sizeof(Pair)*M);
    // int tmp;
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d", &arr[i].v1, &arr[i].v2);
    //     if (arr[i].v1 < arr[i].v2) {
    //         tmp = arr[i].v1;
    //         arr[i].v1 = arr[i].v2;
    //         arr[i].v2 = tmp;
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &M);
    arr = (Pair*) malloc(sizeof(Pair)*M);
    int tmp;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &arr[i].v1, &arr[i].v2);
        if (arr[i].v1 < arr[i].v2) {
            tmp = arr[i].v1;
            arr[i].v1 = arr[i].v2;
            arr[i].v2 = tmp;
        }
    }


    // answer
    qsort(arr, M, sizeof(Pair), compare);
    // for (int i = 0; i < M; i++) {
    //     printf("v1: %d v2: %d\n", arr[i].v1, arr[i].v2);
    // }
    char* ans = (char*) calloc(N+2, sizeof(char));
    ans[N+1] = '\0';
    int low, high;
    for (int i = 2; i <= N; i++) {
        low = lowerBound(i, arr, M);
        high = upperBound(i, arr, M);
        // printf("i: %d low: %d high: %d\n", i, low, high);
        if (high - low == i) ans[i-2] = 'E';
        else if (high - low - 1 == 0) ans[i-2] = 'N';
        else {
            ans[0] = '-';
            ans[1] = '1';
            ans[2] = '\0';
            break; 
        }
    }
    printf("%s\n", ans);


    free(arr);
    free(ans);
    return 0;
}