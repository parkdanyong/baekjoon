/*
    title: 최대 힙
    tag: priority queue, heap


*/


#include <stdio.h>
#include <stdlib.h>


void append(int* heap, int* len, int data) {
    /*
        The number of append does not exceed the heap size in this problem.
        Therefore, skip the check the heap is full.

    */
    
    
    *len += 1;
    heap[*len] = data;
    int cur = *len;
    int parent = 0;
    int tmp = 0;
    while (cur > 1) {
        parent = (int) cur / 2;
        if (heap[cur] > heap[parent]) {
            tmp = heap[cur];
            heap[cur] = heap[parent];
            heap[parent] = tmp;
        }
        cur = parent;
    }
}


int delete(int* heap, int* len) {
    if (*len == 0) return 0;


    int val = heap[1];
    heap[1] = heap[*len];
    *len -= 1;
    int cur = 1;
    int tmp = 0;
    while (cur <= *len) {
        if (cur * 2 + 1 <= *len) { // have two child -> left, right node
            if (heap[cur * 2] > heap[cur * 2 + 1]) {
                if (heap[cur * 2] > heap[cur]) {
                    tmp = heap[cur];
                    heap[cur] = heap[cur * 2];
                    heap[cur * 2] = tmp;
                    cur = cur * 2;    
                }
                else break; // sorted well
            }
            else {
                if (heap[cur * 2 + 1] > heap[cur]) {
                    tmp = heap[cur];
                    heap[cur] = heap[cur * 2 + 1];
                    heap[cur * 2 + 1] = tmp;
                    cur = cur * 2 + 1;
                }
                else break; // sorted well
            }
        }
        else if (cur * 2 <= *len) { // have one child -> left node
            if (heap[cur * 2] > heap[cur]) {
                tmp = heap[cur];
                heap[cur] = heap[cur * 2];
                heap[cur * 2] = tmp;
                cur = cur * 2;    
            }
            else break; // sorted well
        }
        else break; // no child
    }
    

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
    int* heap = (int*) malloc(sizeof(int)*(n + 1)); // for convenience of index operation, 0 is left blank.
    int len = 0;


    // answer
    for (int i = 0; i < n; i++) {
        if (arr[i]) append(heap, &len, arr[i]);
        else printf("%d\n", delete(heap, &len));
    }


    free(arr);
    free(heap);
    return 0;
}