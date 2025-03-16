/*
    title: 문제집
    tag: graph, Topological Sorting, Min-Heap
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int ver;
    struct Node* next;
}Node;


typedef struct Heap {
    int* arr;
    int size;
    int len;
}Heap;



int N, M;
Node** adjList;
Node** rear;


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


void initList() {
    for (int i = 0; i <= N; i++) {
        adjList[i] = NULL;
        rear[i] = NULL;
    }
}


void addPath(int v1, int v2) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->ver = v2;
    new->next = NULL;
    if (rear[v1] == NULL) adjList[v1] = new;
    else rear[v1]->next = new;
    rear[v1] = new;
}


void topologicalSort() {
    Heap* minHeap = createHeap(N+1);
    int* inDeg = (int*) calloc(N+1, sizeof(int));
    Node* u;
    for (int i = 1; i <= N; i++) {
        u = adjList[i];
        while (u) {
            inDeg[u->ver] += 1;
            u = u->next;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) append(minHeap, i);
    }


    int v;
    while (minHeap->len > 0) {
        v = delete(minHeap);
        printf("%d ", v);

        u = adjList[v];
        while (u) {
            inDeg[u->ver] -= 1;
            if (inDeg[u->ver] == 0) append(minHeap, u->ver);
            u = u->next;
        }
    }
    printf("\n");


    free(inDeg);
    freeHeap(minHeap);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &M);
    // adjList = (Node**) malloc(sizeof(Node*)*(N+1));
    // rear = (Node**) malloc(sizeof(Node*)*(N+1));
    // int v1, v2;
    // initList();
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     addPath(v1, v2);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &M);
    adjList = (Node**) malloc(sizeof(Node*)*(N+1));
    rear = (Node**) malloc(sizeof(Node*)*(N+1));
    int v1, v2;
    initList();
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &v1, &v2);
        addPath(v1, v2);
    }


    // answer
    topologicalSort();


    Node* cur;
    Node* del;
    for (int i = 0; i <= N; i++) {
        cur = adjList[i];
        while (cur) {
            del = cur;
            free(del);
            cur = cur->next;
        }
    }
    free(adjList);
    free(rear);
    return 0;
}