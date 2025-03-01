/*
    title: 수 정렬하기 3
    tag: sorting
*/


#include <stdio.h>
#include <stdlib.h>


int main() {
    // input
    int n;
    scanf("%d", &n);
    int* arr = (int*) calloc(10001, sizeof(int));
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        arr[num] += 1;
    }

    
    // answer
    int count = 0;
    for (int i = 1; i <= 10000; i++) {
        count = arr[i];
        for (int j = 0; j < count; j++) {
            printf("%d\n", i);
        }
    }


    free(arr);
    return 0;
}