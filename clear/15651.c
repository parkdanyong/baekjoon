/*
    title: N과 M (3)
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
        arr[count] = i;
        backtrack(count + 1);
    }
}



int main() {
    // input
    scanf("%d %d", &n, &m);

    
    // init
    arr = (int*) malloc(sizeof(int)*(m+1));


    // answer
    backtrack(1);


    free(arr);
    return 0;
}