/*
    title: 피보나치 수 6
    tag: divide & conquer


    F(n) = F(n-1) + F(n-2)
    
    matrix
    |F(n)  | = |1 1| * |F(n-1)|
    |F(n-1)|   |1 0|   |F(n-2)|
    
    
*/



#include <stdio.h>
#include <stdlib.h>


#define DIV 1000000007
#define N 2


typedef long long ll;

ll* matrix;


void matrixMultiply(ll *A, ll *B, ll *C) { // A * B = C
    ll* tmp = (ll*)malloc(sizeof(ll)*4);

    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tmp[N * i + j] = 0;
            for (int k = 0; k < N; k++) {
                tmp[N * i + j] = ((A[N * i + k] * B[N * k + j] % DIV) + tmp[N * i + j]) % DIV;
            }
        }
    }

    
    for (int i = 0; i < N * N; i++) {
        C[i] = tmp[i] % DIV;
    }
    free(tmp);
}


void matrixPower(ll b, ll* result) {
    if (b == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[N * i + j] = (i == j) ? 1 : 0;
            }
        }
        return;
    }
    else if (b == 1) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[N * i + j] = matrix[N * i + j];
            }
        }
        return;
    }


    matrixPower(b/2, result);
    matrixMultiply(result, result, result);
    if (b % 2 == 1) matrixMultiply(matrix, result, result);
}


int main() {
    // input
    ll n;
    scanf("%lld", &n);


    // init
    matrix = (ll*) malloc(sizeof(ll)*4);
    matrix[0] = 1;
    matrix[1] = 1;
    matrix[2] = 1;
    matrix[3] = 0;


    // answer
    ll* result = (ll*) malloc(sizeof(ll)*4);
    matrixPower(n-1, result);
    printf("%lld\n", result[0]);


    free(matrix);
    free(result);
    return 0;
}