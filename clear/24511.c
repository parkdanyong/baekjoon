/*
    title: queuestack
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 100010



typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;


int N, M;
int* arr;
CQ* cq;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int val) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = val;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return 0;

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}



int main() {
    // input
    scanf("%d", &N);
    arr = (int*) malloc(sizeof(int)*N);
    cq = createCQ(MAX_QUEUE_SIZE);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int* stack = (int*) malloc(sizeof(int)*N);
    int top = -1;
    int v;
    for (int i = 0; i < N; i++) {
        scanf("%d", &v);
        if (arr[i] == 0) stack[++top] = v;
    }


    // init
    for (int i = top; i >= 0; i--) {
        enqueue(cq, stack[i]);
    }


    // answer
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &v);
        enqueue(cq, v);
        printf("%d ", dequeue(cq));
    }
    printf("\n");


    free(arr);
    free(stack);
    free(cq->arr);
    free(cq);
    return 0;
}