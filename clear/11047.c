/*
    title: 동전 0
    tag: greedy algorithm
*/




#include <stdio.h>
#include <stdlib.h>


int upperBound(int* arr, int n, int target) {
    int low = -1;
    int high = n;
    int mid = 0;

    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        if (target < arr[mid]) high = mid;
        else low = mid;
    }

    return high;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, k;
    // fscanf(file, "%d %d", &n, &k);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    int n, k;
    scanf("%d %d", &n, &k);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    int maxChange = upperBound(arr, n, k) - 1;
    

    // answer
    int ans = 0;
    for (int i = maxChange; i >= 0; i--) {
        ans += (int) k / arr[i];
        k = k % arr[i];
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}