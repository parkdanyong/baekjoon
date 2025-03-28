/*
    title: 소수
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_NUM 10000


int N, M;
int* arr;


int main() {
    // input
    scanf("%d %d", &N, &M);


    // init
    arr = (int*) calloc(MAX_NUM+1, sizeof(int));
    for (int i = 2; i <= MAX_NUM; i++) {
        arr[i] = 1;
    }


    // answer
    for (int i = 2; i <= MAX_NUM; i++) {
        for (int j = 2; i*j <= MAX_NUM; j++) {
            arr[i*j] = 0;
        }
    }
    int minVal = 0, sum = 0;
    for (int i = N; i <= M; i++) {
        if (arr[i]) {
            if (minVal == 0) minVal = i;
            sum += i;
        }
    }
    if (minVal == 0) printf("-1\n");
    else printf("%d\n%d\n", sum, minVal);


    free(arr);
    return 0;
}