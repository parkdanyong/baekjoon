/*
    title: ATM
    tag: sorting, greedy algorithm
*/



#include <stdio.h>
#include <stdlib.h>


int compare(const void* arg1, const void* arg2) {
    return *(int*) arg1 - *(int*) arg2;
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
    qsort(arr, n, sizeof(int), compare);


    // answer
    int ans = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        ans += sum;
    }
    printf("%d\n", ans);

    

    free(arr);
    return 0;
}