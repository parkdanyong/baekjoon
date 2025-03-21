/*
    LIS: Longest Increasing Subsequence

    1. dp
    O(n^2)

    2. binary search + dp
    O(nlogn)
    
*/


#include <stdlib.h>


int max(int a, int b) {
    return a > b ? a : b;
}


int dp(int* sequence, int n) {
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        arr[i] = 1;
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < i; j++) { // 수열의 끝이 i일 때 최대 길이
            if (sequence[j] < sequence[i]) {
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, arr[i]);
    }
    free(arr);
    return maxLen;
}



int lowerBound(int* dp, int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        if (dp[mid] >= target) high = mid;
        else low = mid;
    }
    return low; 
}


int lengthOfLIS(int* nums, int n) {
    if (n == 0) return 0;

    int* dp = (int*) malloc(sizeof(int)*n);
    int len = 0;

    int pos;
    for (int i = 0; i < n; i++) {
        pos = lowerBound(dp, len, nums[i]);
        dp[pos] = nums[i];  

        if (pos == len) {
            len += 1; 
        }
    }

    free(dp);
    return len;
}