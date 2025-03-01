/*
    title: 숨바꼭질
    tag: graph, BFS




    solution
    BFS guarantees that the first path visited to the end is the shortest one.

*/




#include <stdio.h>
#include <stdlib.h>


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
    int* visited = (int*) calloc(100001, sizeof(int));
    CQ* cq = createCQ(100001);
    visited[n] = 1;
    enqueue(cq, n, 0);
    

    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (cur.pos == k) break;

        // push
        cur.count += 1;
        if (cur.pos + 1 < 100001 && cur.pos < k && visited[cur.pos + 1] == 0) {
            enqueue(cq, cur.pos + 1, cur.count);
            visited[cur.pos + 1] = 1;
        }
        if (0 <= cur.pos - 1 && visited[cur.pos - 1] == 0) {
            enqueue(cq, cur.pos - 1, cur.count);
            visited[cur.pos - 1] = 1;
        }
        if (cur.pos * 2 < 100001 && cur.pos < k && visited[cur.pos * 2] == 0) {
            enqueue(cq, cur.pos * 2, cur.count);
            visited[cur.pos * 2] = 1;
        }
    }


    free(visited);
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