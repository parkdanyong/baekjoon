/*
    title: K번째 수
    tag: sorting
*/




#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b; // ascending order
}



int main() {
    // input
    int n, k;
    scanf("%d %d", &n, &k);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    qsort(arr, n, sizeof(int), compare);


    // answer
    int ans = arr[k-1];
    printf("%d\n", ans);



    free(arr);
    return 0;
}