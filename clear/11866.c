/*
    title: 요세푸스 문제 0
    tag: implement, queue

    
*/




#include <stdio.h>
#include <stdlib.h>



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


void enqueue(CQ* cq, int data) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = data;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return -1;

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int isEmpty(CQ* cq) {
    if (cq->front == cq->rear) return 1;
    else return 0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n = 0, k = 0;
    // fscanf(file, "%d %d", &n, &k);
    // fclose(file);


    // input
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);


    // init
    CQ* cq = createCQ(n + 1);
    for (int i = 1; i <= n; i++) {
        enqueue(cq, i);
    }


    // answer
    int ans= 0;
    printf("<");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            ans = dequeue(cq);
            enqueue(cq, ans);
        }
        ans = dequeue(cq);
        printf("%d", ans);
        if (isEmpty(cq) == 0) printf(", "); 
    }
    printf(">\n");


    free(cq->arr);
    free(cq);
    return 0;
}


