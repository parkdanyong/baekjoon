/*
    title: 수 찾기
    tag: data structure, merge sort, binary search
*/



#include <stdio.h>
#include <stdlib.h>



int* createArr(int size) {
    int* arr = NULL;
    arr = (int*) malloc(sizeof(int) * size);
    return arr;
}


void merge(int* arr, int left, int mid, int right) {
    // init result array
    int size = right - left + 1;
    int index = 0;
    int* result = (int*) malloc(sizeof(int)*(size));

    // init sub arr index
    int index_L = left;
    int index_R = mid+1;
    
    // sorting
    while (!(index_L == mid + 1 || index_R == right + 1)) {
        if (arr[index_L] < arr[index_R]) {
            result[index++] = arr[index_L++];
        }
        else {
            result[index++] = arr[index_R++];
        }
    }

    // wrap up sorting
    while (index_L < mid + 1) {
        result[index++] = arr[index_L++];
    }
    while (index_R < right + 1) {
        result[index++] = arr[index_R++];
    }

    // apply
    for (int i = 0; i < size; i++) {
        arr[i + left] = result[i];
    }
    
    free(result);
}


void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (int) left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right); 
    }
}




int binarySearch(int *arr, int size, int target) { // binary search
    int left = 0; 
    int right = size - 1;
    int mid = 0;

    while (left <= right) {
        mid = (int) (left + (right - left) / 2);
        if (arr[mid] == target) return 1; // find
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return 0; // can not find
}


int main() {
    int size1;
    int size2;
    int* arr1 = NULL;
    int* arr2 = NULL;


    // init arr1
    scanf("%d", &size1);
    arr1 = createArr(size1);
    if (arr1 == NULL) {
        printf("malloc error\n");
        return 1;
    }
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }   
    mergeSort(arr1, 0, size1-1); // O(nlogn)


    // init arr2
    scanf("%d", &size2);
    arr2 = createArr(size2);
    if (arr2 == NULL) {
        printf("malloc error\n");
        free(arr1);
        return 1;
    }
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }


    // check
    for (int i = 0; i < size2; i++) { // O(n)
        printf("%d\n", binarySearch(arr1, size1, arr2[i])); // O(logn)
    }


    free(arr1);
    free(arr2); 


    return 0;
}