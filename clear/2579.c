/*
    title: 계단 오르기
    tag: dp


    Simple instance.
    Function dp() return the maximum sum of steps.

    When n is 6, values of steps. 
    0  1  2  3  4  5  6
    0  10 20 15 25 10 20


    Top-Down method
    dp(6) = max(dp(4), dp(3) + step[5]) + 20
    dp(5) = max(dp(3), dp(2) + step[4]) + 10
    dp(4) = max(dp(2), dp(1) + step[3]) + 25
    dp(3) = max(dp(1), dp(0) + step[2]) + 15
    dp(2) = dp(1) + 20
    dp(1) = 10
    dp(0) = 0

*/




#include <stdio.h>
#include <stdlib.h>
int* arr;
int* mem;


int max(int a, int b) {
    return a > b ? a : b;
}


int dp(int n) {
    if (n == 0) return 0;
    else if (mem[n] != 0) return mem[n];

    mem[n] = dp(n-2);
    int cmp = dp(n-3) + arr[n-1];
    mem[n] = max(cmp, mem[n]) + arr[n];

    return mem[n];
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // arr = (int*) calloc(n+1, sizeof(int));
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    arr = (int*) calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    mem = (int*) calloc(n+1, sizeof(int));
    mem[1] = arr[1];
    mem[2] = mem[1] + arr[2];


    // answer
    // Top-Down
    int ans = dp(n);
    printf("%d\n", ans);

    // Bottom-Up
    // int cmp = 0;
    // for (int i = 3; i <= n; i++) {
    //     mem[i] = max(mem[i-2], mem[i-3] + arr[i-1]) + arr[i];
    //     printf("n: %d val: %d\n", i, mem[i]);
    // }
    // printf("%d\n", mem[n]);


    free(arr);
    free(mem);
    return 0;
}