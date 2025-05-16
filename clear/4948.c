/*
    title: 베르트랑 공준
    tag: 소수
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_ARR_LEN 250000


int N;
int* arr;


int main() {
    // input
    arr = (int*) calloc(MAX_ARR_LEN, sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < MAX_ARR_LEN; i++) {
        for (int j = 2; i*j < MAX_ARR_LEN; j++) {
            arr[i*j] = 1;
        }
    }


    // answer
    int ans = 0;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        ans = 0;
        for (int i = N+1; i <= 2*N; i++) {
            if (!arr[i]) ans += 1;
        }
        printf("%d\n", ans);
    }


    free(arr);
    return 0;
}