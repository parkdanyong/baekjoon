/*
    title: 뱀과 사다리 게임
    tag: graph, BFS

    Maybe it can be solved with Floyd-Warshall algorithm?
    It would be timeout?

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


typedef struct PipeLine {
    int from;
    int to;
}PL;


int ladders, snakes;
int size;
PL* arr;


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


int move(int pos) {
    for (int i = 0; i < size; i++) {
        if (arr[i].from == pos) return arr[i].to;
    }
    return pos;
}


int bfs(int pos, int* visited) {
    CQ* cq = createCQ(110);
    enqueue(cq, pos, 0);

    int tmp;
    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        // printf("pos: %d count: %d\n", cur.pos, cur.count);
        if (cur.pos == 100) break;

        // push
        cur.count += 1;
        for (int i = 1; i <= 6; i++) {
            tmp = move(cur.pos + i);
            if (visited[tmp] == 0) {
                enqueue(cq, tmp, cur.count);
                visited[tmp] = 1;
            }
        }
    }

    return cur.count;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &ladders, &snakes);
    // size = ladders + snakes;
    // arr = (PL*) malloc(sizeof(PL)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d %d", &arr[i].from, &arr[i].to);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &ladders, &snakes);
    size = ladders + snakes;
    arr = (PL*) malloc(sizeof(PL)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d %d", &arr[i].from, &arr[i].to);
    }


    // init
    int* visited = (int*) calloc(110, sizeof(int));
    visited[1] = 1;

    // answer
    int ans = bfs(1, visited);
    printf("%d\n", ans);


    free(arr);
    free(visited);
    return 0;
}

