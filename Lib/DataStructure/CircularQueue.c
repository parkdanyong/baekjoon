/*
    FIFO (first in first out)


    implemented: Array

*/


typedef struct Node {
    int pos;
    int count;
}node;


typedef struct CircularQueue {
    node* arr;
    int size;
    int front;
    int rear;
}CQ;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (node*) malloc(sizeof(node)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int pos, int count) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].pos = pos;
    cq->arr[cmp].count = count;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int getCount(CQ* cq) {
    if (cq->front <= cq->rear) return cq->rear - cq->front;
    else return cq->size + cq->rear - cq->front;
}