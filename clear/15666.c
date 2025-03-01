/*
    title: N과 M (12)
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


    int pre = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[count - 1] <= arr[i] && pre != arr[i]) {
            pre = arr[i];
            ans[count] = arr[i];
            backtrack(count + 1);
        }
    }
}



int main() {    
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // arr = (int*) calloc(n+1, sizeof(int));
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    arr = (int*) calloc(n+1, sizeof(int));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    qsort(arr, n+1, sizeof(int), compare);


    // answer
    ans = (int*) calloc(m+1, sizeof(int));
    backtrack(1);



    free(arr);
    free(ans);
    return 0;
}