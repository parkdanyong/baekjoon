/*
    title: 1, 2, 3 더하기
    tag: dp


    Simple instance.
    n
    1 -> 1 
    2 -> 2 
    3 -> 4
    4 -> 7
    5 -> 13
    6 -> 24
    7 -> 44


    The regularity is as follows (function ans(n) return the number of cases)
    ans(n) = ans(n-1) + ans(n-2) + ans(n-3)
    ans(5) = ans(4) + ans(3) + ans(2) = 7 + 4 + 2 = 13

*/




#include <stdio.h>
#include <stdlib.h>


int dp(int* mem, int n) {
    if (mem[n] != 0) return mem[n];
    
    mem[n] = dp(mem, n-1) + dp(mem, n-2) + dp(mem, n-3);
    return mem[n];
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
    int* mem = (int*) calloc(11, sizeof(int));
    mem[1] = 1;
    mem[2] = 2;
    mem[3] = 4;


    // answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = dp(mem, arr[i]);
        printf("%d\n", ans);
    }



    free(arr);
    free(mem);
    return 0;
}