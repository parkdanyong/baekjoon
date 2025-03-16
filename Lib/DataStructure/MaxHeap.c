typedef struct Heap {
    int* arr;
    int size;
    int len;
}Heap;


Heap* createHeap(int size) {
    Heap* maxHeap = (Heap*) malloc(sizeof(Heap));
    maxHeap->arr = (int*) malloc(sizeof(int)*size);
    maxHeap->size = size;
    maxHeap->len = 0;
    return maxHeap;
}


void freeHeap(Heap* maxHeap) {
    free(maxHeap->arr);
    free(maxHeap);
}


void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void append(Heap* maxHeap, int val) {
    if (maxHeap->len + 1 >= maxHeap->size) return;

    maxHeap->len += 1;
    int len = maxHeap->len;
    int* arr = maxHeap->arr;
    arr[len] = val;

    int cur = len;
    int parent = 0;
    while (cur > 1) {
        parent = (int) cur / 2;
        if (arr[cur] > arr[parent]) swap(&arr[cur], &arr[parent]);
        cur = parent;
    }
}


void heapify(int* arr, int len, int cur) {
    int left;
    int right;
    int biggest;
    while (cur * 2 <= len) { 
        left = cur * 2;
        right = cur * 2 + 1;
        biggest = cur; 

        if (arr[left] > arr[biggest]) biggest = left;
        if (right <= len && arr[right] > arr[biggest]) biggest = right;
        
        if (biggest != cur) {
            swap(&arr[cur], &arr[biggest]);
            cur = biggest;
        }
        else break;    
    }
}


int delete(Heap* maxHeap) {
    if (maxHeap->len == 0) return 0;

    int* arr = maxHeap->arr;
    int val = arr[1];
    arr[1] = arr[maxHeap->len];
    maxHeap->len -= 1;
    heapify(arr, maxHeap->len, 1);

    return val;
}