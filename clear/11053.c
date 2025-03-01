/*
    title: 가장 긴 증가하는 부분 수열
    tag: dp, LIS


*/


#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    return a > b ? a : b;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    int* dp = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }


    // answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);


    free(arr);
    free(dp);
    return 0;
}