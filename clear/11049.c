/*
    title: 행렬 곱셈 순서
    tag: dp

    dp[i][j]: (i ~ k) * (k+1 ~ j)
*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


#define min(X, Y) (X) < (Y) ? (X) : (Y)



typedef struct Pair {
    int v1;
    int v2;
}Pair;


int N, size;
Pair* arr;
int* mem;



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // size = N*N;
    // arr = (Pair*) malloc(sizeof(Pair)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d %d", &arr[i].v1, &arr[i].v2);
    // }
    // mem = (int*) calloc(size, sizeof(int));
    // int cmp;
    // for (int i = 1; i < N; i++) {
    //     for (int j = 0; j < N-i; j++) {
    //         mem[N*j + (j+i)] = INT_MAX;
    //         for (int k = j; k < j+i; k++) {
    //             cmp = mem[N*j + k] + mem[N*(k+1) + j+i] + arr[j].v1 * arr[k].v2 * arr[i+j].v2;
    //             mem[N*j + (j+i)] = min(mem[N*j + (j+i)], cmp);
    //         }
    //     }
    // }
    // printf("%d\n", mem[N-1]);
    // fclose(file);
    

    // input
    scanf("%d", &N);
    size = N*N;
    arr = (Pair*) malloc(sizeof(Pair)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].v1, &arr[i].v2);
    }


    // init
    mem = (int*) calloc(size, sizeof(int));


    // answer
    int cmp;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N-i; j++) {
            mem[N*j + (j+i)] = INT_MAX;
            for (int k = j; k < j+i; k++) {
                cmp = mem[N*j + k] + mem[N*(k+1) + j+i] + arr[j].v1 * arr[k].v2 * arr[i+j].v2;
                mem[N*j + (j+i)] = min(mem[N*j + (j+i)], cmp);
            }
        }
    }
    printf("%d\n", mem[N-1]);


    free(arr);
    free(mem);
    return 0;
}