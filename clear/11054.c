/*
    title: 가장 긴 바이토닉 부분 수열
    tag: dp 

    오른쪽, 왼쪽 끝을 기준으로 2개의 LIS
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int inc;
    int dec;
}pair;


int n;
int* arr;


int max(int a, int b) {
    return a > b ? a : b;
}


int dp(int* sequence) {
    pair* len = (pair*) malloc(sizeof(pair)*n);
    for (int i = 0; i < n; i++) {
        len[i].inc = 1;
        len[i].dec = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                len[i].inc = max(len[i].inc, len[j].inc + 1);
            }
            if (sequence[n - 1 - j] < sequence[n - 1 - i]) {
                len[n - 1 - i].dec = max(len[n - 1 - i].dec, len[n - 1 - j].dec + 1);
            }
        }
    }


    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        maxLen = max(maxLen, len[i].inc + len[i].dec - 1);
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
    

    free(arr);
    return 0;
}