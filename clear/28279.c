/*
    title: 덱 2
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Dequeue {
    int* arr;
    int size;
    int front;
    int rear;
}Dequeue;


int N;
Dequeue* deque;


Dequeue* createDequeue(int size) {
    Dequeue* deque = (Dequeue*) malloc(sizeof(Dequeue));
    deque->arr = (int*) malloc(sizeof(int)*size);
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


int deleteFront(Dequeue* deque) {
    if (deque->front == deque->rear) return -1; // empty

    deque->front = (deque->front + 1) % deque->size;
    return deque->arr[deque->front];
}


int deleteRear(Dequeue* deque) {
    if (deque->front == deque->rear) return -1; // empty

    int rv = deque->arr[deque->rear];
    deque->rear = (deque->size + deque->rear - 1) % deque->size;
    return rv;
}


int getCount(Dequeue* deque) {
    if (deque->front <= deque->rear) return deque->rear - deque->front;
    else return deque->size + deque->rear - deque->front;
}



int main() {
    // input
    scanf("%d", &N);
    deque = createDequeue(N+1);
    int command;
    for (int i = 0; i < N; i++) {
        scanf("%d", &command);
        if (command == 1) {
            scanf("%d", &command);
            addFront(deque, command);
        }
        else if (command == 2) {
            scanf("%d", &command);
            addRear(deque, command);
        }
        else if (command == 3) {
            if (getCount(deque) == 0) printf("-1\n");
            else printf("%d\n", deleteFront(deque));
        }
        else if (command == 4) {
            if (getCount(deque) == 0) printf("-1\n");
            else printf("%d\n", deleteRear(deque));
        }
        else if (command == 5) printf("%d\n", getCount(deque));
        else if (command == 6) getCount(deque) == 0 ? printf("1\n") : printf("0\n");
        else if (command == 7) {
            if (getCount(deque) == 0) printf("-1\n");
            else printf("%d\n", deque->arr[(deque->front + 1) % deque->size]);
        }
        else if (command == 8) {
            if (getCount(deque) == 0) printf("-1\n");
            else printf("%d\n", deque->arr[deque->rear]);
        }
    }


    free(deque->arr);
    free(deque);
    return 0;
}