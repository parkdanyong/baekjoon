/*
    title: 줄 세우기
    tag: graph, Topological Sorting, DAG (Directed Acyclic Graph)
*/



#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int ver;
    struct Node* next;
}Node;


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;




int n, m;
Node** AdjList;
Node** rear;




CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int ver) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = ver;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return 0;

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int initList() {
    for (int i = 0; i <= n; i++) {
        AdjList[i] = NULL;
        rear[i] = NULL;
    }
}


void addPath(int v1, int v2) {
    Node* new = (Node*) malloc(sizeof(Node));
    new->ver = v2;
    new->next = NULL;

    if (rear[v1] == NULL) {
        AdjList[v1] = new;
        rear[v1] = new;
    }
    else {
        rear[v1]->next = new;
        rear[v1] = new;
    }
}


void clearList() {
    Node* cur;
    Node* del;
    for (int i = 0; i <= n; i++) {
        cur = AdjList[i];
        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);
        }
    }
}


void topologicalSort() {
    CQ* cq = createCQ(n+2);
    int* inDeg = (int*) calloc(n+1, sizeof(int));
    Node* u;
    for (int i = 1; i <= n; i++) {
        u = AdjList[i];
        while (u) {
            inDeg[u->ver] += 1;
            u = u->next;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) enqueue(cq, i);
    }


    int v;
    while (cq->front != cq->rear) {
        v = dequeue(cq);
        printf("%d ", v);

        u = AdjList[v];
        while (u) {
            inDeg[u->ver] -= 1;
            if (inDeg[u->ver] == 0) enqueue(cq, u->ver);
            u = u->next;
        }
    }
    printf("\n");
    
    
    free(inDeg);
    free(cq->arr);
    free(cq);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // AdjList = (Node**) malloc(sizeof(Node*)*(n+1));
    // rear = (Node**) malloc(sizeof(Node*)*(n+1));
    // initList();
    // int v1, v2;
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     addPath(v1, v2);
    // }
    // topologicalSort();
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);


    // init
    AdjList = (Node**) malloc(sizeof(Node*)*(n+1));
    rear = (Node**) malloc(sizeof(Node*)*(n+1));
    initList();
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        addPath(v1, v2);
    }


    // answer
    topologicalSort();


    clearList();
    free(AdjList);
    free(rear);
    return 0;
}