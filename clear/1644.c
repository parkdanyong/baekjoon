/*
    title: 소수의 연속합
    tag: Two-Pointer, Sieve of Eratosthenes
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


int main() {
    // input
    int n;
    scanf("%d", &n);


    // init
    int* arr = (int*) calloc(n+1, sizeof(int));
    ll* prefixSum = (ll*) calloc(n+1, sizeof(ll));
    for (int i = 2; i <= n; i++) {
        arr[i] = 1;
    }
    int tmp;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) continue;
        tmp = 2;
        while (i*tmp <= n) {
            arr[i*tmp] = 0;
            tmp += 1;
        }
    }
    prefixSum[0] = 0;
    int len = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i]) {
            prefixSum[len] += prefixSum[len-1] + (ll) i;
            len += 1;
        }
    }


    // answer
    int left = 0, right = len-1;
    int ans = 0;
    while (left < right) {
        if (prefixSum[right] - prefixSum[left] > n) {
            if (left < right-1 && prefixSum[right-1] - prefixSum[left] >= n) right -= 1;
            else left += 1;
        }
        else if (prefixSum[right] - prefixSum[left] < n) {
            if (right < len-1) right += 1;
            else break;
        }
        else {
            ans += 1;
            left += 1;
        }
    }
    printf("%d\n", ans);


    free(arr);
    free(prefixSum);
    return 0;
}