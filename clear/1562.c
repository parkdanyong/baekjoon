/*
    title: 계단 수
    tag: dp, bit-masking
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define DIV_NUM 1000000000
#define BITMASK 1024
#define MAX_NUM 100


int N;
int ans;
int arr[MAX_NUM+1][10][BITMASK];



void dp() {
    int nextBit = 0;
    for (int pos = 1; pos < N; pos++) {
        for (int n = 0; n < 10; n++) {
            for (int bit = 0; bit < BITMASK; bit++) {
                if (arr[pos][n][bit] == 0) continue;

                if (0 < n) {
                    nextBit = bit | 1 << (n-1);
                    arr[pos+1][n-1][nextBit] = (arr[pos+1][n-1][nextBit] + arr[pos][n][bit]) % DIV_NUM;
                }
                if (n < 9) {
                    nextBit = bit | 1 << (n+1);
                    arr[pos+1][n+1][nextBit] = (arr[pos+1][n+1][nextBit] + arr[pos][n][bit]) % DIV_NUM;
                }
            }
        }
    }
}


int main() {
    // input
    scanf("%d", &N);  
    

    // init
    memset(arr, 0, sizeof(int)*(MAX_NUM+1)*10*BITMASK);
    for (int i = 1; i < 10; i++) {
        arr[1][i][1 << i] = 1;
    }


    // answer
    dp();
    ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans + arr[N][i][1023]) % DIV_NUM;
    }
    printf("%d\n", ans);

    
    return 0;
}