/*
    Dequeue

*/


typedef struct Dequeue {
    int* arr;
    int size;
    int front;
    int rear;
}Dequeue;


Dequeue* createDequeue(int size) {
    Dequeue* deque = (Dequeue*) malloc(sizeof(Dequeue));
    deque->arr = (char*) malloc(sizeof(char)*size);
    deque->size = size;
    deque->front = 0;
    deque->rear = 0;
    return deque;
}


void addFront(Dequeue* deque, int val) {
    int cmp = (deque->size + deque->front - 1) % deque->size;
    if (deque->rear == cmp) return; // full

    deque->arr[deque->front] = val;
    deque->front = cmp;
}


void addRear(Dequeue* deque, int val) {
    int cmp = (deque->rear + 1) % deque->size;
    if (deque->front == cmp) return; // full

    deque->rear = cmp;
    deque->arr[cmp] = val;
}


void deleteFront(Dequeue* deque) {
    if (deque->front == deque->rear) return; // empty

    deque->front = (deque->front + 1) % deque->size;
    return deque->arr[deque->front];
}


void deleteRear(Dequeue* deque) {
    if (deque->front == deque->rear) return; // empty

    // int rv = deque->arr[deque->rear];
    deque->rear = (deque->size + deque->rear - 1) % deque->size;
    // return rv;
}


int getCount(Dequeue* deque) {
    if (deque->front <= deque->rear) return deque->rear - deque->front;
    else return deque->size + deque->rear - deque->front;
}