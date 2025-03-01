/*
    title: N과 M (5)
    tag: backtracking
*/



#include <stdio.h>
#include <stdlib.h>


int n, m;
int* arr;
int* ans;


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


void backtrack(int count) {
    if (count > m) {
        for (int i = 1; i <= m; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }


    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= count-1; j++) {
            if (ans[j] == arr[i]) flag = 0;
        }
        if (flag) {
            ans[count] = arr[i];
            backtrack(count + 1);
        }
        flag = 1;
    }
}


int main() {
    // input
    scanf("%d %d", &n, &m);
    arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    qsort(arr, n, sizeof(int), compare);


    // answer
    ans = (int*) malloc(sizeof(int)*(m+1));
    backtrack(1);



    free(arr);
    free(ans);
    return 0;
}