/*
    title: 토마토
    tag: graph, BFS

    
*/



#include <stdio.h>
#include <stdlib.h>
int* arr;
int rows, cols;




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


int bfs(int* ripe, int c, int size) {
    CQ* cq = createCQ(size);
    for (int i = 0; i < c; i++) {
        enqueue(cq, ripe[i], 0);
    }

    node cur = {0, 0};
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);

        // printf("pos: %d count: %d\n", cur.pos, cur.count);
        // push
        if (cur.pos + 1 < size && cur.pos % cols + 1 < cols) { // there is space on right
            if (arr[cur.pos + 1] == 0) { // can move
                enqueue(cq, cur.pos + 1, cur.count+1);
                arr[cur.pos + 1] = 1;
            }
        }
        if (0 <= cur.pos - 1 && 0 <= cur.pos % cols - 1) { // there is space on left
            if (arr[cur.pos - 1] == 0) { // can move
                enqueue(cq, cur.pos - 1, cur.count+1);
                arr[cur.pos - 1] = 1;
            }
        }
        if (0 <= cur.pos - cols) { // there is space on up
            if (arr[cur.pos - cols] == 0) { // can move
                enqueue(cq, cur.pos - cols, cur.count+1);
                arr[cur.pos - cols] = 1;
            }
        }
        if (cur.pos + cols < size) { // there is space on down
            if (arr[cur.pos + cols] == 0) { // can move
                enqueue(cq, cur.pos + cols, cur.count+1);
                arr[cur.pos + cols] = 1;
            }
        }
    }


    free(cq->arr);
    free(cq);
    return cur.count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &cols, &rows);
    // int size = rows*cols;
    // arr = (int*) calloc(size, sizeof(int));
    // int* ripe = (int*) calloc(size, sizeof(int));
    // int c = 0;
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 1) ripe[c++] = i;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &cols, &rows);
    int size = rows*cols;
    arr = (int*) calloc(size, sizeof(int));
    int* ripe = (int*) calloc(size, sizeof(int));
    int c = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) ripe[c++] = i;
    }


    // init
    /* 
        I don't need visited array because i start bfs with all of ripe tomatoes.
        Instead, it should be changed to 1 after moving.
    */ 


    // answer
    int ans = bfs(ripe, c, size);
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            ans = -1;
            break;
        }
    }
    printf("%d\n", ans);


    free(arr);
    free(ripe);
    return 0;
}