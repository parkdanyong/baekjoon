/*
    title: 다리 놓기
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_ARR_SIZE 900


typedef long long ll;


int T, N, M;
ll* arr;


void initArr() {
    for (int i = 0; i < 30; i++) {
        arr[i] = i+1;
        arr[30*i + i] = 1;
    }
    for (int i = 1; i < 30; i++) {
        for (int j = i; j < 30; j++) {
            arr[30*i + j] = arr[30*i + (j-1)] + arr[30*(i-1) + (j-1)];
        }
    }
}



int main() {
    // input
    arr = (ll*) calloc(MAX_ARR_SIZE, sizeof(ll));
    initArr();
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &N, &M);
        printf("%lld\n", arr[30*(N-1) + (M-1)]);
    }



    free(arr);
    return 0;
}