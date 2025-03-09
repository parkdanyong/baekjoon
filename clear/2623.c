/*
    title: 음악프로그램
    tag: graph, Topological Sorting
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Vertex {
    int n;
    struct Vertex* next;
}Vertex;


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;




int N, M;
Vertex** AdjList;
Vertex** rear;




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


void initList() {
    for (int i = 0; i <= N; i++) {
        AdjList[i] = NULL;
        rear[i] = NULL;
    }
}


void addPath(int v1, int v2) {
    Vertex* new = (Vertex*) malloc(sizeof(Vertex));
    new->n = v2;
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
    Vertex* cur;
    Vertex* del;
    for (int i = 0; i <= N; i++) {
        cur = AdjList[i];
        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);
        }
        AdjList[i] = NULL;
        rear[i] = NULL;
    }
}


void topologicalSort() {
    CQ* cq = createCQ(N+2);
    int* inDeg = (int*) calloc(N+1, sizeof(int));
    Vertex* u;
    for (int i = 1; i <= N; i++) {
        u = AdjList[i];
        while (u) {
            inDeg[u->n] += 1;
            u = u->next;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (inDeg[i] == 0) enqueue(cq, i);
    }


    int v;
    int* stack = (int*) malloc(sizeof(int)*N);
    int top = -1;
    while (cq->front != cq->rear) {
        v = dequeue(cq);
        stack[++top] = v;

        u = AdjList[v];
        while (u) {
            inDeg[u->n] -= 1;
            if (inDeg[u->n] == 0) enqueue(cq, u->n);
            u = u->next;
        }
    }
    if (top != N-1) printf("0\n");
    else {
        for (int i = 0; i < N; i++) {
            printf("%d\n", stack[i]);
        }
    }
    

    free(cq->arr);
    free(cq);
    free(inDeg);
    free(stack);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &M);
    // AdjList = (Vertex**) malloc(sizeof(Vertex*)*(N+1));
    // rear = (Vertex**) malloc(sizeof(Vertex*)*(N+1));
    // initList();
    // int tmp, v1, v2;
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d", &tmp);
    //     fscanf(file, "%d", &v1);
    //     for (int j = 1; j < tmp; j++) {
    //         fscanf(file, "%d", &v2);
    //         addPath(v1, v2);
    //         v1 = v2;
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &M);
    AdjList = (Vertex**) malloc(sizeof(Vertex*)*(N+1));
    rear = (Vertex**) malloc(sizeof(Vertex*)*(N+1));
    initList();
    int tmp, v1, v2;
    for (int i = 0; i < M; i++) {
        scanf("%d", &tmp);
        scanf("%d", &v1);
        for (int j = 1; j < tmp; j++) {
            scanf("%d", &v2);
            addPath(v1, v2);
            v1 = v2;
        }
    }


    // answer
    topologicalSort();


    clearList();
    free(AdjList);
    free(rear);
    return 0;
}