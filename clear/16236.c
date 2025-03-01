/*
    title: 아기 상어
    tag: graph, BFS

    up -> left -> right -> down
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 1000


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


int n, size;
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


node bfs(int pos, int state) {
    int* visited = (int*) calloc(size, sizeof(int));
    visited[pos] = 1;
    CQ* cq = createCQ(size+1);
    enqueue(cq, pos, 0);

    node* stack = (node*) malloc(sizeof(node)*size);
    int top = 0;
    stack[0].pos = 0;
    stack->count = INF;
    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (arr[cur.pos] != 0 && arr[cur.pos] < state) {
            if (cur.count <= stack[top].count) stack[++top] = cur;
            else break;
        }

        // push
        if (0 <= cur.pos - n) { // up
            if (arr[cur.pos - n] <= state && visited[cur.pos - n] == 0) {
                visited[cur.pos - n] = 1;
                enqueue(cq, cur.pos - n, cur.count + 1);
            }
        }
        if (0 <= cur.pos - 1 && 0 <= cur.pos % n - 1) { // left
            if (arr[cur.pos - 1] <= state && visited[cur.pos - 1] == 0) {
                visited[cur.pos - 1] = 1;
                enqueue(cq, cur.pos - 1, cur.count + 1);
            }
        }
        if (cur.pos + 1 < size && cur.pos % n + 1 < n) { // right
            if (arr[cur.pos + 1] <= state && visited[cur.pos + 1] == 0) {
                visited[cur.pos + 1] = 1;
                enqueue(cq, cur.pos + 1, cur.count + 1);
            }
        }
        if (cur.pos + n < size) { // down
            if (arr[cur.pos + n] <= state && visited[cur.pos + n] == 0) {
                visited[cur.pos + n] = 1;
                enqueue(cq, cur.pos + n, cur.count + 1);
            }
        }
    }


    free(visited);
    free(cq->arr);
    free(cq);
    cur.pos = INF;
    cur.count = INF;
    for (int i = 1; i <= top; i++) {
        if (stack[i].pos < cur.pos) cur = stack[i];
    }
    return cur;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // size = n * n;
    // node babyShark = {0, 0};
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 9) {
    //         babyShark.pos = i;
    //         arr[i] = 0;
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    size = n * n;
    node babyShark = {0, 0};
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 9) {
            babyShark.pos = i;
            arr[i] = 0;
        }
    }
    

    // answer
    int level = 2;
    int eatingCount = 0;
    int ans = 0;
    while (1) {
        babyShark = bfs(babyShark.pos, level);
        if (babyShark.pos == INF) break;
        arr[babyShark.pos] = 0;
        ans += babyShark.count;
        eatingCount += 1;
        if (eatingCount == level) {
            eatingCount = 0;
            level += 1;
        }
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}