/*
    title: 최단경로
    tag: graph, shortest path, dijkstra
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INF 1000000000


typedef struct Node {
    int ver;
    int weight;
    struct Node* next;
}node;


typedef struct Heap {
    node* arr;
    int size;
    int len;
}heap;


int n, e;
node** arr;
node** back;


int min(int a, int b) {
    return a < b ? a : b;
}


node* createNode(int v2, int weight) {
    node* new = (node*) malloc(sizeof(node));
    new->ver = v2;
    new->weight = weight;
    new->next = NULL;
    return new;
}


void addPath(int v1, int v2, int weight) {
    if (back[v1] == NULL) {
        arr[v1] = createNode(v2, weight);
        back[v1] = arr[v1];
        return;
    }

    back[v1]->next = createNode(v2, weight);
    back[v1] = back[v1]->next;
}


heap* createHeap(int size) {
    heap* minHeap = (heap*) malloc(sizeof(heap));
    minHeap->arr = (node*) malloc(sizeof(node)*size);
    minHeap->size = size;
    minHeap->len = 0;
    return minHeap;
}


void swap(node* a, node* b) {
    node tmp;
    memcpy(&tmp, a, sizeof(node));
    memcpy(a, b, sizeof(node));
    memcpy(b, &tmp, sizeof(node));
}


void append(heap* minHeap, int ver, int weight) {
    if (minHeap->len + 1 >= minHeap->size) return;

    minHeap->len += 1;
    int len = minHeap->len;
    node* arr = minHeap->arr;
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


void heapify(node* arr, int len, int cur) {
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


node delete(heap* minHeap) {
    if (minHeap->len == 0) {
        node tmp = {-1 , -1};
        return tmp;
    }

    node* arr = minHeap->arr;
    node val = arr[1];
    arr[1] = arr[minHeap->len];
    minHeap->len -= 1;
    heapify(arr, minHeap->len, 1);

    return val;
}


void dijkstra(int start) {
    int* dist = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    heap* minHeap = createHeap(e+2);
    append(minHeap, start, 0);
    
    node* dest;
    node mid;
    while (minHeap->len > 0) {
        mid = delete(minHeap);
        if (mid.weight > dist[mid.ver]) continue;

        dest = arr[mid.ver];
        while (dest) {
            int v = dest->ver;
            int w = dest->weight;

            if (dist[mid.ver] + w < dist[v]) {
                dist[v] = dist[mid.ver] + w;
                append(minHeap, v, dist[v]);
            } 
            dest = dest->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) printf("INF\n");
        else printf("%d\n", dist[i]);
    }
    free(dist);
    free(minHeap->arr);
    free(minHeap);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &e);
    // int pos = 0;
    // fscanf(file, "%d", &pos);
    // arr = (node**) malloc(sizeof(node*)*(n+1));
    // back = (node**) malloc(sizeof(node*)*(n+1));
    // for (int i = 0; i <= n; i++) {
    //     arr[i] = NULL;
    //     back[i] = NULL;
    // }
    // int v1, v2, weight;
    // node* cur;
    // for (int i = 0; i < e; i++) {
    //     fscanf(file, "%d %d %d", &v1, &v2, &weight);
    //     addPath(v1, v2, weight);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &n, &e);
    int pos = 0;
    scanf("%d", &pos);
    arr = (node**) malloc(sizeof(node*)*(n+1));
    back = (node**) malloc(sizeof(node*)*(n+1));
    for (int i = 0; i <= n; i++) {
        arr[i] = NULL;
        back[i] = NULL;
    }
    int v1, v2, weight;
    node* cur;
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        addPath(v1, v2, weight);
    }


    // answer
    dijkstra(pos);


    node* next;
    for (int i = 0; i <= n; i++) {
        cur = arr[i];
        while (cur) {
            next = cur->next;
            free(cur);
            cur = next;
        }
    } 
    free(arr);
    free(back);
    return 0;
}