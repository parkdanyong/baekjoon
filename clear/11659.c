/*
    title: 구간 합 구하기 4
    tag: prefix sum (누적합)
*/



#include <stdio.h>
#include <stdlib.h>


void prefixSum(int* arr, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
        arr[i] = sum;
    }
}


int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    n += 1;
    int* arr = (int*) malloc(sizeof(int)*n);
    arr[0] = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    prefixSum(arr, n);


    // answer
    int ans = 0;
    int left, right;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &left, &right);
        ans = arr[right] - arr[left - 1];
        printf("%d\n", ans);
    }


    free(arr);
    return 0;
}