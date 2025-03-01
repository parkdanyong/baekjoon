/*
    title: 최소 힙
    tag: priority queue, heap
*/




#include <stdio.h>
#include <stdlib.h>


typedef struct Heap {
    int* arr;
    int size;
    int len;
}heap;


heap* createHeap(int size) {
    heap* minHeap = (heap*) malloc(sizeof(heap));
    minHeap->arr = (int*) malloc(sizeof(int)*size);
    minHeap->size = size;
    minHeap->len = 0;
    return minHeap;
}


void freeHeap(heap* minHeap) {
    free(minHeap->arr);
    free(minHeap);
}


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void append(heap* minHeap, int val) {
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


int delete(heap* minHeap) {
    if (minHeap->len == 0) return 0;

    int* arr = minHeap->arr;
    int val = arr[1];
    arr[1] = arr[minHeap->len];
    minHeap->len -= 1;
    heapify(arr, minHeap->len, 1);

    return val;
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
    heap* minHeap = createHeap(n+1);


    // answer
    for (int i = 0; i < n; i++) {
        if (arr[i]) append(minHeap, arr[i]);
        else printf("%d\n", delete(minHeap));
    }


    free(arr);
    freeHeap(minHeap);
    return 0;
}