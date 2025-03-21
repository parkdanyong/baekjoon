/*
    title: 가장 긴 증가하는 부분 수열 2
    tag: binary search, LIS
    
*/



#include <stdio.h>
#include <stdlib.h>


int N;
int* arr;


int lowerBound(int* dp, int size, int target) {
    int low = -1;
    int high = size;
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

    int pos = 0;
    for (int i = 0; i < n; i++) {
        pos = lowerBound(dp, len, nums[i]) + 1;
        dp[pos] = nums[i];  

        if (pos == len) {
            len += 1; 
        }
    }

    free(dp);
    return len;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // arr = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    arr = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int ans = lengthOfLIS(arr, N);
    printf("%d\n", ans);


    free(arr);
    return 0;
}