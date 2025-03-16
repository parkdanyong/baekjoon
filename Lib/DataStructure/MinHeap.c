#include <stdlib.h>


typedef struct Heap {
    int* arr;
    int size;
    int len;
}Heap;


Heap* createHeap(int size) {
    Heap* minHeap = (Heap*) malloc(sizeof(Heap));
    minHeap->arr = (int*) malloc(sizeof(int)*size);
    minHeap->size = size;
    minHeap->len = 0;
    return minHeap;
}


void freeHeap(Heap* minHeap) {
    free(minHeap->arr);
    free(minHeap);
}


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void append(Heap* minHeap, int val) {
    if (minHeap->len + 1 >= minHeap->size) return;

    minHeap->len += 1;
    int len = minHeap->len;
    int* arr = minHeap->arr;
    arr[len] = val;

    int cur = len;
    int parent = 0;
    while (cur > 1) {
        parent = (int) cur / 2;
        if (arr[cur] < arr[parent]) swap(&arr[cur], &arr[parent]);
        cur = parent;
    }
}


void heapify(int* arr, int len, int cur) {
    int left;
    int right;
    int smallest;
    while (cur * 2 <= len) { 
        left = cur * 2;
        right = cur * 2 + 1;
        smallest = cur; 

        if (arr[left] < arr[smallest]) smallest = left;
        if (right <= len && arr[right] < arr[smallest]) smallest = right;
        
        if (smallest != cur) {
            swap(&arr[cur], &arr[smallest]);
            cur = smallest;
        }
        else break;    
    }
}


int delete(Heap* minHeap) {
    if (minHeap->len == 0) return 0;

    int* arr = minHeap->arr;
    int val = arr[1];
    arr[1] = arr[minHeap->len];
    minHeap->len -= 1;
    heapify(arr, minHeap->len, 1);

    return val;
}