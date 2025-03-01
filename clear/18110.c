/*
    title: solved.ac
    tag: math, sorting
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


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
    int del = (int) floor((double) n * 0.15 + 0.5);
    int count = n - 2*del;


    // answer
    double ans = 0;
    for (int i = del; i < n - del; i++) {
        ans += (double) arr[i];
    }
    if (count == 0) ans = 0;
    else ans = floor(ans / (double) count + 0.5);
    printf("%d\n", (int) ans);


    free(arr);
    return 0;
}