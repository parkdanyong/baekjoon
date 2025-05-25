/*
    title: 푸앙이와 콩나무
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Node {
    int pos;
    int count;
    int water;
}Node;


typedef struct CircularQueue {
    Node* arr;
    int size;
    int front;
    int rear;
}CQ;



int N;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (Node*) malloc(sizeof(Node)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int pos, int count, int water) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].pos = pos;
    cq->arr[cmp].count = count;
    cq->arr[cmp].water = water;
}


Node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        Node tmp = {-1, -1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


void bfs() {
    CQ* cq = createCQ(N+1);
    enqueue(cq, N, 0, 0);
    int* visited = (int*) calloc(N, sizeof(int));
    visited[N] = 1;
    
    
    Node ans = {-1, -1, -1};
    Node cur;
    while (1) {
        // pop
        cur = dequeue(cq);
        if (cur.pos == 0) {
            if (ans.count == -1) ans = cur;
            else if (ans.count == cur.count && cur.water < ans.water) ans = cur;
            else break;
        } 

        // push
    }
    printf("%d %d\n", ans.count, ans.water);


    free(cq->arr);
    free(cq);
}


int main() {
    // input
    scanf("%d", &N);


    // answer
    bfs();

    
    return 0;
}