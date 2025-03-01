/*
    title: 행렬 제곱
    tag: math, divide and conquer
*/



#include <stdio.h>
#include <stdlib.h>


#define REMAINDER 1000


typedef long long ll;


ll N, size, B;
ll* arr;
ll* result;


void matrixMultiply(ll *A, ll *B, ll *C) { // A * B = C
    ll* tmp = (ll*)malloc(sizeof(ll)*size);

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[N * i + j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[N * i + j] += A[N * i + k] * B[N * k + j] % REMAINDER;
            }
        }
    }

    
    for (int i = 0; i < N * N; i++) {
        C[i] = tmp[i] % REMAINDER;
    }
    free(tmp);
}


void matrixPower(ll b) {
    if (b == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i * N + j] = (i == j) ? 1 : 0;
            }
        }
        return;
    }
    else if (b == 1) {
        for (int i = 0; i < size; i++) {
            result[i] = arr[i];
        }
        return;
    }

    matrixPower(b/2);
    matrixMultiply(result, result, result);
    if (b % 2 == 1) matrixMultiply(result, arr, result); 
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%lld %lld", &N, &B);
    // size = N * N;
    // arr = (ll*) malloc(sizeof(ll)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%lld %lld", &N, &B);
    size = N * N;
    arr = (ll*) malloc(sizeof(ll)*size);
    for (int i = 0; i < size; i++) {
        scanf("%lld", &arr[i]);
    }


    // init
    result = (ll*) malloc(sizeof(ll)*size);
    for (int i = 0; i < size; i++) {
        arr[i] %= REMAINDER;
    }


    // answer
    matrixPower(B);
    for (int i = 0; i < size; i++) {
        printf("%lld ", result[i]);
        if ((i+1) % N == 0) printf("\n");
    }


    free(arr);
    free(result);
    return 0;
}