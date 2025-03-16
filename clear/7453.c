/*
    title: 합이 0인 네 정수
    tag: Two-Pointer, sorting, binary search, meet in the middle
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;



int N, size;
int* A;
int* B;
int* C;
int* D;
int* S1;
int* S2;


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


int upperBound(int target) {
    int low = -1;
    int high = size;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (S2[mid] + target <= 0) low = mid;
        else high = mid;
    }
    return high;
}


int lowerBound(int target) {
    int low = -1;
    int high = size;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (S2[mid] + target >= 0) high = mid;
        else low = mid;
    }
    return low;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // A = (int*) malloc(sizeof(int)*N);
    // B = (int*) malloc(sizeof(int)*N);
    // C = (int*) malloc(sizeof(int)*N);
    // D = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    A = (int*) malloc(sizeof(int)*N);
    B = (int*) malloc(sizeof(int)*N);
    C = (int*) malloc(sizeof(int)*N);
    D = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
    }


    // init
    size = N * N;
    S1 = malloc(sizeof(int)*size);
    S2 = malloc(sizeof(int)*size);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            S1[N*i + j] = A[i] + B[j];
            S2[N*i + j] = C[i] + D[j];
        }
    }
    qsort(S2, size, sizeof(int), compare);


    // answer
    int low, high;
    ll ans = 0;
    for (int i = 0; i < size; i++) {
        ans += (upperBound(S1[i]) - lowerBound(S1[i]) - 1);
    }
    printf("%lld\n", ans);


    free(A);
    free(B);
    free(C);
    free(D);
    free(S1);
    free(S2);
    return 0;
}