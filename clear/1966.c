/*
    title: 프린터 큐
    tag: queue, simulation
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int num;
    int priority;
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


void enqueue(CQ* cq, int num, int priority) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].num = num;
    cq->arr[cmp].priority = priority;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int isPriority(CQ* cq, int priority) {
    node* arr = cq->arr;
    int size = cq->size;
    int end = (cq->rear + 1) % size;
    int cur = (cq->front + 1) % size;
    while (cur != end) {
        if (priority < arr[cur].priority) return 0;
        cur = (cur + 1) % size;
    }
    return 1;
}


void clearCQ(CQ* cq) {
    cq->front = 0;
    cq->rear = 0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int T;
    // fscanf(file, "%d", &T);
    // CQ* cq = createCQ(110);
    // int n, m, tmp, count = 0;
    // node document = {-1, -1};
    // for (int i = 0; i < T; i++) {
    //     fscanf(file, "%d %d", &n, &m);
    //     for (int j = 0; j < n; j++) {
    //         fscanf(file, "%d", &tmp);
    //         enqueue(cq, j, tmp);
    //     }

    //     while (1) {
    //         document = dequeue(cq);
    //         if (isPriority(cq, document.priority)) {
    //             count += 1;
    //             if (document.num == m) break;
    //         }
    //         else enqueue(cq, document.num, document.priority);
    //     }

    //     printf("%d\n", count);
    //     clearCQ(cq);
    //     count = 0;
    // }
    // fclose(file);


    // input
    int T;
    scanf("%d", &T);
    CQ* cq = createCQ(110);
    int n, m, tmp, count = 0;
    node document = {-1, -1};
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++) {
            scanf("%d", &tmp);
            enqueue(cq, j, tmp);
        }

        while (1) {
            document = dequeue(cq);
            if (isPriority(cq, document.priority)) {
                count += 1;
                if (document.num == m) break;
            }
            else enqueue(cq, document.num, document.priority);
        }

        printf("%d\n", count);
        clearCQ(cq);
        count = 0;
    }


    free(cq->arr);
    free(cq);
    return 0;
}