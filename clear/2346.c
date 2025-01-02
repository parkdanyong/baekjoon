#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int num;
    int data;
    struct Node* next;
}Node;


typedef struct CirclarQueue {
    Node* head;
    Node* tail;
    int size;
}CirclarQueue;


Node* create(int num, int data) {
    Node* newNode = NULL;
    newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) return NULL;

    newNode->num = num;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}



int pushWithNum(CirclarQueue* cq, int num, int data) {
    Node* newNode = create(num, data);
    if (newNode == NULL) return NULL; // malloc error


    if (cq->size == 0) { // is empty
        cq->head = newNode;
        cq->tail = newNode;
    }
    else {
        newNode->next = cq->head;
        (cq->tail)->next = newNode;
        cq->tail = newNode;
    }

    cq->size += 1;

    return 0; // exec well
}


int popWithNum(CirclarQueue* cq) {
    if (cq->size <= 0) return NULL;


    Node* tmp = cq->head;
    int data = tmp->data;
    printf("%d ", tmp->num);

    if (cq->size == 1) {
        cq->head = NULL;
        cq->tail = NULL;
    }
    else if (cq->size == 2) {
        cq->head = cq->tail;
        (cq->head)->next = NULL;
    }
    else {
        cq->head = (cq->head)->next;
        (cq->tail)->next = cq->head;
    }

    free(tmp);

    cq->size -= 1;

    return data;
}


int moveHead(CirclarQueue* cq, int move) {
    if (cq->size <= 1) return NULL; // empty

    int tmp;
    if (move < 0) tmp = move - 1;
    else tmp = move - 2;
    
    if (tmp < 0) tmp = cq->size - ((-tmp) % cq->size);
    else tmp = tmp % cq->size;
    
    Node* pre = cq->head;
    for (int i = 0; i < tmp; i++) {
        pre = pre->next;
    }

    cq->tail = pre;
    cq->head = pre->next;

    return 0;
}

void freeAll(CirclarQueue* cq) {
    while (1) {
        if (popWithNum(cq) == -1) break;
    }
}


int main() {
    CirclarQueue cq;
    cq.head = NULL;
    cq.tail = NULL;
    cq.size = 0;

    int count = 0;
    int data = 0;

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &data);
        pushWithNum(&cq, i + 1, data);
    }


    for (int i = 0; i < count; i++) {
        data = popWithNum(&cq);
        if (cq.size == 0) break;
        moveHead(&cq, data);
    }


    return 0;
}



