/*
    title: N과 M (9)
    tag: backtracking
*/



#include <stdio.h>
#include <stdlib.h>


int n, m;
int* arr;
int* lock;
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


    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (pre != arr[i] && lock[i] == 0) {
            pre = arr[i];
            lock[i] = 1;
            ans[count] = arr[i];
            backtrack(count + 1);
            lock[i] = 0;
        }
    }
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // arr = (int*) calloc(n, sizeof(int));
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    arr = (int*) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    qsort(arr, n, sizeof(int), compare);
    lock = (int*) calloc(n, sizeof(int));


    // answer
    ans = (int*) calloc(m+1, sizeof(int));
    backtrack(1);


    free(arr);
    free(lock);
    free(ans);
    return 0;
}