/*
    title: 2×n 타일링
    tag: dp

    n
    1 -> 1
    2 -> 2
    3 -> 3
    4 -> 5
    5 -> 8

*/



#include <stdio.h>
#include <stdlib.h>


int dp(int*arr, int n) {
    if (arr[n] != 0) return arr[n];
    else if (n == 0) return 1;
    else if (n == 1) return 1;
    else {
        arr[n] = (dp(arr, n-1) + dp(arr, n-2)) % 10007;
        return arr[n];
    }
}




int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    int* arr = (int*) calloc(n+1, sizeof(int));
    arr[0] = 1;
    arr[1] = 1;
    int ans = dp(arr, n);
    printf("%d\n", ans);



    free(arr);
    return 0;
}