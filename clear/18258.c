/*
    title: 큐
    tag: data structure, queue
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;


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
    if (cq->front == cq->rear) return -1;
    
    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // CQ* cq = createCQ(n+1);
    // char command[20];
    // int val;
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%s", command);
    //     if (strcmp(command, "push") == 0) {
    //         fscanf(file, "%d", &val);
    //         enqueue(cq, val);
    //     }
    //     else if (strcmp(command, "pop") == 0) {
    //         printf("%d\n", dequeue(cq));
    //     }
    //     else if (strcmp(command, "size") == 0) {
    //         if (cq->front <= cq->rear) printf("%d\n", cq->rear - cq->front);
    //         else printf("%d\n", cq->size + cq->front - cq->rear - 2);
    //     }
    //     else if (strcmp(command, "empty") == 0) {
    //         if (cq->front == cq->rear) printf("0\n");
    //         else printf("1\n");
    //     }
    //     else if (strcmp(command, "front") == 0) {
    //         if (cq->front == cq->rear) printf("-1\n");
    //         else printf("%d\n", cq->arr[(cq->front + 1) % cq->size]);
    //     }
    //     else if (strcmp(command, "back") == 0) {
    //         if (cq->front == cq->rear) printf("-1\n");
    //         else printf("%d\n", cq->arr[cq->rear]);
    //     }
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    CQ* cq = createCQ(n+1);
    char command[20];
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d", &val);
            enqueue(cq, val);
        }
        else if (strcmp(command, "pop") == 0) {
            printf("%d\n", dequeue(cq));
        }
        else if (strcmp(command, "size") == 0) {
            if (cq->front <= cq->rear) printf("%d\n", cq->rear - cq->front);
            else printf("%d\n", cq->size + cq->front - cq->rear - 2);
        }
        else if (strcmp(command, "empty") == 0) {
            if (cq->front == cq->rear) printf("1\n");
            else printf("0\n");
        }
        else if (strcmp(command, "front") == 0) {
            if (cq->front == cq->rear) printf("-1\n");
            else printf("%d\n", cq->arr[(cq->front + 1) % cq->size]);
        }
        else if (strcmp(command, "back") == 0) {
            if (cq->front == cq->rear) printf("-1\n");
            else printf("%d\n", cq->arr[cq->rear]);
        }
    }
    

    free(cq->arr);
    free(cq);
    return 0;
}