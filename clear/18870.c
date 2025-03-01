/*
    title: 좌표 압축
    tag: sotring, value/coordinate compression
*/




#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b; // ascending order
}


int lowerBound(int* arr, int n, int target) {
    int low = -1;
    int high = n;
    int mid = 0;

    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        
        if (arr[mid] < target) low = mid;
        else high = mid;
    }

    return low;
}


int removeDuplicates(int* arr, int n) {
    int len = 0;

    for (int i = 1; i < n; i++) {
        if (arr[len] != arr[i]) {
            len++;
            arr[len] = arr[i];
        }
    }

    return len + 1;
}




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // int* preprocessed = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     preprocessed[i] = arr[i];
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);
    int* preprocessed = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        preprocessed[i] = arr[i];
    }


    // init
    qsort(preprocessed, n, sizeof(int), compare);
    int len = removeDuplicates(preprocessed, n);
    

    // answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = lowerBound(preprocessed, len, arr[i]);
        printf("%d ", ans + 1);
    }
    printf("\n");


    free(arr);
    free(preprocessed);
    return 0;
}