/*
    title: AC
    tag: dequeue, string, parsing

    I solved it using modified circular queue.

*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




typedef struct CircularQueue {
    int front;
    int rear;
    int size;
    int clockwise;
    int* arr;
}CQ;



CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->clockwise = 1;
    cq->front = 3;
    cq->rear = 3;

    return cq;
}


void clearCQ(CQ* cq) {
    cq->front = 3;
    cq->rear = 3;
    cq->clockwise = 1;
}


void freeCQ(CQ* cq) {
    free(cq->arr);
    free(cq);
}


void reverse(CQ* cq) {
    int tmp = 0;
    if (cq->clockwise) {
        cq->clockwise = 0;
        tmp = cq->rear;
        cq->rear = (cq->front + 1) % cq->size;
        cq->front = (tmp + 1) % cq->size;
    }
    else {
        cq->clockwise = 1;
        tmp = cq->rear;
        cq->rear = (cq->size + cq->front - 1) % cq->size;
        cq->front = (cq->size + tmp - 1) % cq->size;
    }
}


void enqueue(CQ* cq, int data) { 
    int tmp;
    if (cq->clockwise) {
        tmp = (cq->rear + 1) % cq->size;
    }
    else {
        tmp = (cq->size + cq->rear - 1) % cq->size;
    }
    if (cq->front == tmp) return;


    cq->rear = tmp;
    cq->arr[cq->rear] = data;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return -1;
    
    if (cq->clockwise) {
        cq->front = (cq->front + 1) % cq->size;
    }
    else {
        cq->front = (cq->size + cq->front - 1) % cq->size;
    }
    
    return cq->arr[cq->front];
}


void answer(CQ* cq, char* command) {
    int len = strlen(command);
    for (int i = 0; i < len; i++) {
        if (command[i] == 'D') {
            if (dequeue(cq) == -1) {
                printf("error\n");
                return;
            }
        }
        else reverse(cq);
    }

    int data = dequeue(cq);
    printf("[");
    while (data != -1) { 
        printf("%d", data);
        data = dequeue(cq);
        if (data == -1) break;
        printf(",");
    }
    printf("]\n");
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int t;
    // char command[100001];
    // int size;
    // CQ* cq = createCQ(100001);
    // char tmp[200002];
    // char* token;
    // fscanf(file, "%d", &t);
    // for (int i = 0; i < t; i++) {
    //     fscanf(file, "%s", command);
    //     fscanf(file, "%d", &size);
    //     fscanf(file, "%s", tmp);
    //     token = strtok(tmp, "[],");
    //     while (token != NULL) {
    //         enqueue(cq, atoi(token));
    //         token = strtok(NULL, "[],");
    //     }
    //     answer(cq, command);
    //     clearCQ(cq);
    // }
    // fclose(file);


    // input
    int t;
    char command[100010];
    int size;
    CQ* cq = createCQ(100010);
    char tmp[200010];
    char* token;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", command);
        scanf("%d", &size);
        scanf("%s", tmp);
        token = strtok(tmp, "[],");
        while (token != NULL) {
            enqueue(cq, atoi(token));
            token = strtok(NULL, "[],");
        }
        answer(cq, command);
        clearCQ(cq);
    }



    freeCQ(cq);
    return 0;
}