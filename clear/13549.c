/*
    title: 숨바꼭질 3
    tag: graph, BFS, shortest path, Dijkstra, 0-1 BFS


    Push priority is important. 
    1. *
    2. -
    3. +

    Simple instances
    0 3
    0 + 1 -> 1
    1 * 2 -> 2 
    2 + 1 -> 3
    answer: 2
    

    4 6
    4 - 1 -> 3
    3 * 2 -> 6
    answer 1

*/



#include <stdio.h>
#include <stdlib.h>


#define MAXPOSITION 100000


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


int bfs(int n, int k) {
    int* visited = (int*) calloc(MAXPOSITION + 1, sizeof(int));
    visited[n] = 1;
    CQ* cq = createCQ(MAXPOSITION + 1);
    enqueue(cq, n, 0);

    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (cur.pos == k) break;

        // push
        if (cur.pos * 2 <= MAXPOSITION && visited[cur.pos * 2] == 0) {
            visited[cur.pos * 2] = 1;
            enqueue(cq, cur.pos * 2, cur.count);
        }
        if (0 <= cur.pos - 1 && visited[cur.pos - 1] == 0) {
            visited[cur.pos - 1] = 1;
            enqueue(cq, cur.pos - 1, cur.count + 1);
        }
        if (cur.pos + 1 <= MAXPOSITION && visited[cur.pos + 1] == 0) {
            visited[cur.pos + 1] = 1;
            enqueue(cq, cur.pos + 1, cur.count + 1);
        }
    }

    free(cq->arr);
    free(cq);
    return cur.count;
}


int main() {
    // input
    int n, k;
    scanf("%d %d", &n, &k);


    // answer
    int ans = bfs(n, k);
    printf("%d\n", ans);


    return 0;
}