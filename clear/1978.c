/*
    title: 소수 찾기
    tag: math

*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // input
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int ans = 0;
    int cur = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cur = arr[i];
        for (int j = 1; j < cur + 1; j++) {
            if ((int) cur % j == 0) count++;
        }
        if (count == 2) ans++;
        count = 0;
    }
    printf("%d\n", ans);



    free(arr);
    return 0;
}