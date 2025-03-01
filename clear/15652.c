/*
    title: N과 M (4)
    tag: backtracking
*/


#include <stdio.h>
#include <stdlib.h>


int n, m;
int* arr;


void backtrack(int count) {
    if (count > m) {
        for (int i = 1; i <= m; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }


    for (int i = 1; i <= n; i++) {
        if (arr[count - 1] <= i) {
            arr[count] = i;
            backtrack(count + 1);
        }
    }
}


int main() {
    // input
    scanf("%d %d", &n, &m);


    // init
    arr = (int*) calloc(m+1, sizeof(int));


    // answer
    backtrack(1);


    free(arr);
    return 0;
}