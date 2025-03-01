/*
    title: 소수 구하기
    tag: Sieve of Eratosthenes
*/


#include <stdio.h>
#include <stdlib.h> 



int main() {
    // input
    int low, high;
    scanf("%d %d", &low, &high);


    // init
    int* arr = (int*) calloc(high+1, sizeof(int));
    arr[1] = 1;


    // answer
    for (int i = 2; i <= high; i++) {
        for (int j = 2; i*j <= high; j++) {
            arr[i*j] = 1;
        }
    }
    for (int i = low; i <= high; i++) {
        if (arr[i] == 0) printf("%d\n", i);
    }


    free(arr);
    return 0;
}