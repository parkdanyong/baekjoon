/*
    title: 숨바꼭질 2
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100000


typedef struct Node {
    int pos;
    int sec;
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


void enqueue(CQ* cq, int pos, int sec) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].pos = pos;
    cq->arr[cmp].sec = sec;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


void bfs(int n, int k) {
    node* visited = (node*) calloc(MAX_SIZE+1 ,sizeof(node));
    visited[n].pos = 1;
    visited[n].sec = 0;
    CQ* cq = createCQ(MAX_SIZE+1);
    enqueue(cq, n, 0);


    int minTime = MAX_SIZE;
    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (cur.pos == k) {
            if (cur.sec <= minTime) minTime = cur.sec;
            else break;
        }


        // push
        if (cur.pos + 1 <= MAX_SIZE && (visited[cur.pos + 1].pos == 0 || cur.sec + 1 <= visited[cur.pos + 1].sec)) {
            visited[cur.pos + 1].pos += 1;
            visited[cur.pos + 1].sec = cur.sec + 1;
            enqueue(cq, cur.pos + 1, cur.sec + 1);
        }
        if (0 <= cur.pos - 1 && (visited[cur.pos - 1].pos == 0 || cur.sec + 1 <= visited[cur.pos - 1].sec)) {
            visited[cur.pos - 1].pos += 1;
            visited[cur.pos - 1].sec = cur.sec + 1;
            enqueue(cq, cur.pos - 1, cur.sec + 1);
        }
        if (cur.pos * 2 <= MAX_SIZE && (visited[cur.pos * 2].pos == 0 || cur.sec + 1 <= visited[cur.pos * 2].sec)) {
            visited[cur.pos * 2].pos += 1;
            visited[cur.pos * 2].sec = cur.sec + 1;
            enqueue(cq, cur.pos * 2, cur.sec + 1);
        }
    }


    printf("%d\n", visited[k].sec);
    printf("%d\n", visited[k].pos);
    free(visited);
    free(cq->arr);
    free(cq);
}



int main() {
    // input
    int n, k;
    scanf("%d %d", &n, &k);


    // answer
    bfs(n, k);


    return 0;
}