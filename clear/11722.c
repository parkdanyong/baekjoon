/*
    title: 가장 긴 감소하는 부분 수열
    tag: dp
*/



#include <stdio.h>
#include <stdlib.h>


int n;
int* arr;


int max(int a, int b) {
    return a > b ? a : b;
}


int dp(int* sequence) {
    int* len = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        len[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] > sequence[i]) {
                len[i] = max(len[i], len[j] + 1);
            }
        }
    }


    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, len[i]);
    }
    free(len);
    return maxLen;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int ans = dp(arr);
    printf("%d\n", ans);


    return 0;
}