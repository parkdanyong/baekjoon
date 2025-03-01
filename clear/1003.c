/*
    title: 피보나치 함수
    tag: dp
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int c0;
    int c1;
}pair;



int fibonacci(int n, int* mem, pair* ans) {
    if (mem[n] != 0) return mem[n];

    if (n == 0) {
        ans[0].c0 = 1;
        ans[0].c1 = 0;
        return 0;
    }
    else if (n == 1) {
        ans[1].c0 = 0;
        ans[1].c1 = 1;
        return 1;
    }
    else {
        mem[n] = fibonacci(n - 1, mem, ans) + fibonacci(n - 2, mem, ans);
        ans[n].c0 = ans[n - 1].c0 + ans[n - 2].c0;
        ans[n].c1 = ans[n - 1].c1 + ans[n - 2].c1;
        return mem[n];
    }
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


    // answer
    int* mem = (int*) calloc(40, sizeof(int));
    pair* ans = (pair*) malloc(sizeof(pair)*40);
    int cur;
    for (int i = 0; i < n; i++) {
        cur = arr[i];
        fibonacci(cur, mem, ans);
        printf("%d %d\n", ans[cur].c0, ans[cur].c1);
    }


    free(arr);
    free(mem);
    free(ans);
    return 0;
}