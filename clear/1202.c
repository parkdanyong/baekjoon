/*
    title: 보석 도둑
    tag: greedy, sorting, priority queue
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


typedef struct Pair {
    int w;
    int v;
}Pair;


typedef struct Heap {
    int* arr;
    int size;
    int len;
}Heap;




int N, K;
Pair* jewel;
int* bag;
Heap* heap;




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


int compare_j(const void* arg1, const void* arg2) {
    Pair* a = (Pair*) arg1;
    Pair* b = (Pair*) arg2;
    return a->w - b->w;   
}


int compare_b(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}



void addList(Heap* maxHeap, int* from, int w) {
    int cur = *from;
    while (cur < N) {
        if (jewel[cur].w > w) break;
        append(maxHeap, jewel[cur++].v);
    }
    *from = cur;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &K);
    // jewel = (Pair*) malloc(sizeof(Pair)*N);
    // bag = (int*) malloc(sizeof(int)*K);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d %d", &jewel[i].w, &jewel[i].v);
    // }for (int i = 0; i < K; i++) {
    //     fscanf(file, "%d", &bag[i]);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &K);
    jewel = (Pair*) malloc(sizeof(Pair)*N);
    bag = (int*) malloc(sizeof(int)*K);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &jewel[i].w, &jewel[i].v);
    }for (int i = 0; i < K; i++) {
        scanf("%d", &bag[i]);
    }


    // init
    qsort(jewel, N, sizeof(Pair), compare_j);
    qsort(bag, K, sizeof(int), compare_b);
    heap = createHeap(N+1);
    


    // answer
    int from = 0;
    ll ans = 0;
    for (int i = 0; i < K; i++) {
        addList(heap, &from, bag[i]);
        ans = ans + (ll) delete(heap);
    }
    printf("%lld\n", ans);


    free(jewel);
    free(bag);
    freeHeap(heap);
    return 0;
}