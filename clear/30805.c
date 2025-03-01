/*
    title: 사전 순 최대 공통 부분 수열
    tag: greedy algorithm
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int v1;
    int v2;
}pair;


int max(int a, int b) {
    return a > b ? a : b;
}


int compare(const void* arg1, const void* arg2) {
    pair* a = (pair*) arg1;
    pair* b = (pair*) arg2;
    int cmp = b->v1 - a->v1;
    if (cmp == 0) return a->v2 - b->v2;
    else return cmp;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // pair* A = (pair*) malloc(sizeof(pair)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &A[i].v1);
    //     A[i].v2 = i;
    // }
    // int m;
    // fscanf(file, "%d", &m);
    // pair* B = (pair*) malloc(sizeof(pair)*m);
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d", &B[i].v1);
    //     B[i].v2 = i;
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    pair* A = (pair*) malloc(sizeof(pair)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i].v1);
        A[i].v2 = i;
    }
    int m;
    scanf("%d", &m);
    pair* B = (pair*) malloc(sizeof(pair)*m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i].v1);
        B[i].v2 = i;
    }


    // init
    qsort(A, n, sizeof(pair), compare);
    qsort(B, m, sizeof(pair), compare);
    int size = max(n, m);
    int len = 0;
    int* arr = (int*) malloc(sizeof(int)*size);


    // answer
    int A_index = -1;
    int B_index = -1;
    int a = 0;
    int b = 0;
    while (a < n && b < m) {
        if (A[a].v2 < A_index) a += 1;
        else if (B[b].v2 < B_index) b += 1;
        else if (A[a].v1 > B[b].v1) a += 1;
        else if (A[a].v1 < B[b].v1) b += 1;
        else if (A[a].v1 == B[b].v1) {
            arr[len++] = A[a].v1;
            A_index = A[a].v2;
            B_index = B[b].v2;
            a += 1;
            b += 1;
        }
    }
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    free(A);
    free(B);
    free(arr);
    return 0;
}
