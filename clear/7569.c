/*
    title: 토마토
    tag: graph, BFS
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


int cols, rows, height;
int box, all;
int* arr;


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


int bfs(CQ* cq) {
    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        // printf("pos: %d count: %d\n", cur.pos, cur.count);

        // push
        cur.count += 1;
        if (cur.pos + 1 < all && cur.pos % box + 1 < box && cur.pos % cols + 1 < cols) { // has a place on the right
            if (arr[cur.pos + 1] == 0) { // can move to the right
                arr[cur.pos + 1] = 1; // ripe
                enqueue(cq, cur.pos + 1, cur.count);
            }
        }
        if (0 <= cur.pos - 1 && 0 <= cur.pos % box - 1 && 0 <= cur.pos % cols - 1) { // has a place on the left
            if (arr[cur.pos - 1] == 0) { // can move to the left
                arr[cur.pos - 1] = 1; // ripe
                enqueue(cq, cur.pos - 1, cur.count);
            }
        }
        if (0 <= cur.pos - cols && 0 <= cur.pos % box - cols) { // has a place on the up
            if (arr[cur.pos - cols] == 0) { // can move to the up
                arr[cur.pos - cols] = 1; // ripe
                enqueue(cq, cur.pos - cols, cur.count);
            }
        }
        if (cur.pos + cols < all && cur.pos % box + cols < box) { // has a place on the down
            if (arr[cur.pos + cols] == 0) { // can move to the down
                arr[cur.pos + cols] = 1; // ripe
                enqueue(cq, cur.pos + cols, cur.count);
            }
        }
        if (cur.pos + box < all) { // has a place on the upstair
            if (arr[cur.pos + box] == 0) { // can move to the upstair
                arr[cur.pos + box] = 1; // ripe
                enqueue(cq, cur.pos + box, cur.count);
            }
        }
        if (0 <= cur.pos - box) { // has a place on the downstair
            if (arr[cur.pos - box] == 0) { // can move to the downstair
                arr[cur.pos - box] = 1; // ripe
                enqueue(cq, cur.pos - box, cur.count);
            }
        }
    }

    return cur.count - 1;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &cols, &rows, &height);
    // box = rows * cols;
    // all = box * height;
    // CQ* cq = createCQ(1000100);
    // arr = (int*) malloc(sizeof(int)*all);
    // for (int i = 0; i < all; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 1) enqueue(cq, i, 0);
    // }
    // fclose(file);


    // input
    scanf("%d %d %d", &cols, &rows, &height);
    box = rows * cols;
    all = box * height;
    CQ* cq = createCQ(1000010);
    arr = (int*) malloc(sizeof(int)*all);
    for (int i = 0; i < all; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) enqueue(cq, i, 0);
    }


    // answer
    int ans = bfs(cq);
    for (int i = 0; i < all; i++) {
        if (arr[i] == 0) {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);
    

    free(arr);
    free(cq->arr);
    free(cq);
    return 0;
}