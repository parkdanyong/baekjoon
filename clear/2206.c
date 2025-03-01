/*
    title: 벽 부수고 이동하기
    tag: graph, BFS
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int v1;
    int v2;
}pair;


typedef struct Node {
    int pos;
    int count;
    int skill;
}node;


typedef struct CircularQueue {
    node* arr;
    int size;
    int front;
    int rear;
}CQ;


int rows, cols, size;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (node*) malloc(sizeof(node)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int pos, int count, int skill) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].pos = pos;
    cq->arr[cmp].count = count;
    cq->arr[cmp].skill = skill;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int bfs(int start, int end) {
    pair* visited = (pair*) calloc(size, sizeof(pair));
    visited[start].v1 = 1;
    visited[start].v2 = 0;
    CQ* cq = createCQ(size+1);
    enqueue(cq, start, 1, 1);

    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (cur.pos == end) break;


        // push
        if (cur.pos + 1 < size && cur.pos % cols + 1 < cols) { // right
            if (cur.skill) {
                if (arr[cur.pos + 1] == 0 && visited[cur.pos + 1].v1 == 0) {
                    visited[cur.pos + 1].v1 = 1;
                    enqueue(cq, cur.pos + 1, cur.count + 1, 1);
                }
                else if (arr[cur.pos + 1] == 1 && visited[cur.pos + 1].v2 == 0) {
                    visited[cur.pos + 1].v2 = 1;
                    enqueue(cq, cur.pos + 1, cur.count + 1, 0);
                }
            }
            else {
                if (arr[cur.pos + 1] == 0 && visited[cur.pos + 1].v2 == 0) {
                    visited[cur.pos + 1].v2 = 1;
                    enqueue(cq, cur.pos + 1, cur.count + 1, 0);
                }
            }
        }
        if (0 <= cur.pos - 1 && 0 <= cur.pos % cols - 1) { // left
            if (cur.skill) {
                if (arr[cur.pos - 1] == 0 && visited[cur.pos - 1].v1 == 0) {
                    visited[cur.pos - 1].v1 = 1;
                    enqueue(cq, cur.pos - 1, cur.count + 1, 1);
                }
                else if (arr[cur.pos - 1] == 1 && visited[cur.pos - 1].v2 == 0) {
                    visited[cur.pos - 1].v2 = 1;
                    enqueue(cq, cur.pos - 1, cur.count + 1, 0);
                }
            }
            else {
                if (arr[cur.pos - 1] == 0 && visited[cur.pos - 1].v2 == 0) {
                    visited[cur.pos - 1].v2 = 1;
                    enqueue(cq, cur.pos - 1, cur.count + 1, 0);
                }
            }
        }
        if (cur.pos + cols < size) { // down
            if (cur.skill) {
                if (arr[cur.pos + cols] == 0 && visited[cur.pos + cols].v1 == 0) {
                    visited[cur.pos + cols].v1 = 1;
                    enqueue(cq, cur.pos + cols, cur.count + 1, 1);
                }
                else if (arr[cur.pos + cols] == 1 && visited[cur.pos + cols].v2 == 0) {
                    visited[cur.pos + cols].v2 = 1;
                    enqueue(cq, cur.pos + cols, cur.count + 1, 0);
                }
            }
            else {
                if (arr[cur.pos + cols] == 0 && visited[cur.pos + cols].v2 == 0) {
                    visited[cur.pos + cols].v2 = 1;
                    enqueue(cq, cur.pos + cols, cur.count + 1, 0);
                }
            }
        }
        if (0 <= cur.pos - cols) { // up
            if (cur.skill) {
                if (arr[cur.pos - cols] == 0 && visited[cur.pos - cols].v1 == 0) {
                    visited[cur.pos - cols].v1 = 1;
                    enqueue(cq, cur.pos - cols, cur.count + 1, 1);
                }
                else if (arr[cur.pos - cols] == 1 && visited[cur.pos - cols].v2 == 0) {
                    visited[cur.pos - cols].v2 = 1;
                    enqueue(cq, cur.pos - cols, cur.count + 1, 0);
                }
            }
            else {
                if (arr[cur.pos - cols] == 0 && visited[cur.pos - cols].v2 == 0) {
                    visited[cur.pos - cols].v2 = 1;
                    enqueue(cq, cur.pos - cols, cur.count + 1, 0);
                }
            }
        }
    }

    free(visited);
    free(cq->arr);
    free(cq);
    if (cur.pos == end) return cur.count;
    else return -1;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (int*) malloc(sizeof(int)*size);
    // char tmp;
    // for (int i = 0; i < size; i++) {
    //     tmp = fgetc(file);
    //     if (tmp == '\n') i -= 1;
    //     else arr[i] = tmp - '0';
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (int*) malloc(sizeof(int)*size);
    char tmp;
    for (int i = 0; i < size; i++) {
        tmp = fgetc(stdin);
        if (tmp == '\n') i -= 1;
        else arr[i] = tmp - '0';
    }


    // answer
    int ans = bfs(0, size-1);
    printf("%d\n", ans);
    

    free(arr);
    return 0;
}