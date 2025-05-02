/*
    title: 보물
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


int N;
int* A;
int* B;


int DESC(const void* a, const void* b) {
    return *(int*) b - *(int*) a;
}


int ASC(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // A = (int*) malloc(sizeof(int)*N);
    // B = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &A[i]);
    // }
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &B[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    A = (int*) malloc(sizeof(int)*N);
    B = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }


    // init
    qsort(A, N, sizeof(int), ASC);
    qsort(B, N, sizeof(int), DESC);


    // answer
    int ans = 0;
    for (int i = 0;i < N; i++) {
        ans += A[i] * B[i];
    }
    printf("%d\n", ans);



    free(A);
    free(B);
    return 0;
}