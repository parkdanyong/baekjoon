/*
    O((e+v)logv)

    graph: one to all
    rev_grap: all to one
*/

#include <stdlib.h>


#define INF 100000000


typedef struct Pair {
    int ver;
    int weight;
}pair;


typedef struct Heap {
    pair* arr;
    int size;
    int len;
}heap;


int n, m, size;
int* arr;


heap* createHeap(int size) {
    heap* minHeap = (heap*) malloc(sizeof(heap));
    minHeap->arr = (pair*) malloc(sizeof(pair)*size);
    minHeap->size = size;
    minHeap->len = 0;
    return minHeap;
}


void swap(pair* a, pair* b) {
    pair tmp = *a;
    *a = *b;
    *b = tmp;
}


void append(heap* minHeap, int ver, int weight) {
    if (minHeap->len + 1 >= minHeap->size) return;

    minHeap->len += 1;
    int len = minHeap->len;
    pair* arr = minHeap->arr;
    arr[len].ver = ver;
    arr[len].weight = weight;

    int cur = len;
    int parent = 0;
    while (cur > 1) {
        parent = (int) cur / 2;
        if (arr[cur].weight < arr[parent].weight) swap(&arr[cur], &arr[parent]);
        cur = parent;
    }
}


void heapify(pair* arr, int len, int cur) {
    int left;
    int right;
    int smallest;
    while (cur * 2 <= len) { 
        left = cur * 2;
        right = cur * 2 + 1;
        smallest = cur; 

        if (arr[left].weight < arr[smallest].weight) smallest = left;
        if (right <= len && arr[right].weight < arr[smallest].weight) smallest = right;
        
        if (smallest != cur) {
            swap(&arr[cur], &arr[smallest]);
            cur = smallest;
        }
        else break;    
    }
}


pair delete(heap* minHeap) {
    if (minHeap->len == 0) {
        pair tmp = {-1 , -1};
        return tmp;
    }

    pair* arr = minHeap->arr;
    pair val = arr[1];
    arr[1] = arr[minHeap->len];
    minHeap->len -= 1;
    heapify(arr, minHeap->len, 1);

    return val;
}


int min(int a, int b) {
    return a < b ? a : b;
}


int dijkstra(int start, int end) {
    int* dist = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    heap* minHeap = createHeap(m+2);
    append(minHeap, start, 0);

    pair u;
    while (minHeap->len > 0) {
        u = delete(minHeap);
        if (u.weight > dist[u.ver]) continue;
        
        for (int v = 1; v <= n; v++) {
            if (dist[u.ver] + arr[(n+1)*u.ver + v] < dist[v]) {
                dist[v] = dist[u.ver] + arr[(n+1)*u.ver + v];
                append(minHeap, v, dist[v]);
            }
        }
    }

    int val = dist[end];
    free(dist);
    free(minHeap->arr);
    free(minHeap);
    return val;
}