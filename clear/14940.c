/*
    title: 쉬운 최단거리
    tag: graph, BFS


    A -> B distance == B -> A distance
    Start in '2' and find minimum distance for all position.
*/




#include <stdio.h>
#include <stdlib.h>




typedef struct Node {
    int pos;
    int distance;
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


void enqueue(CQ* cq, int pos, int distance) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].pos = pos;
    cq->arr[cmp].distance = distance;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


void bfs(int* arr, int rows, int cols, int* visited, int target) {
    // init queue and visited
    CQ* cq = createCQ(rows*cols+1);
    visited[target] = 1;
    enqueue(cq, target, 0);
    arr[target] = 0;


    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        // printf("pos: %d distance: %d\n", cur.pos, cur.distance);

        // push
        cur.distance += 1;
        if (cur.pos + 1 < rows*cols && cur.pos % cols + 1 < cols) { // there is space on right
            if (arr[cur.pos + 1] != 0 && visited[cur.pos + 1] == 0) { // can move right
                enqueue(cq, cur.pos + 1, cur.distance);
                visited[cur.pos + 1] = 1;
                arr[cur.pos + 1] = cur.distance;
            } 
        }
        if (0 <= cur.pos - 1 && 0 <= cur.pos % cols - 1) { // there is space on left
            if (arr[cur.pos - 1] != 0 && visited[cur.pos - 1] == 0) { // can move left
                enqueue(cq, cur.pos - 1, cur.distance);
                visited[cur.pos - 1] = 1;
                arr[cur.pos - 1] = cur.distance;
            }
        }
        if (cur.pos + cols < rows*cols) { // there is space on up
            if (arr[cur.pos + cols] != 0 && visited[cur.pos + cols] == 0) { // can move up
                enqueue(cq, cur.pos + cols, cur.distance);
                visited[cur.pos + cols] = 1;
                arr[cur.pos + cols] = cur.distance;
            }
        }
        if (0 <= cur.pos - cols) { // there is space on down
            if (arr[cur.pos - cols] != 0 && visited[cur.pos - cols] == 0) { // can move down
                enqueue(cq, cur.pos - cols, cur.distance);
                visited[cur.pos - cols] = 1;
                arr[cur.pos - cols] = cur.distance;
            }
        }
    }


    free(cq->arr);
    free(cq);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int rows, cols;
    // fscanf(file, "%d %d", &rows, &cols);
    // int size = rows*cols;
    // int* arr = (int*) malloc(sizeof(int)*size);
    // int target = 0;
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 2) target = i;
    // }
    // fclose(file);


    // input
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    int size = rows*cols;
    int* arr = (int*) malloc(sizeof(int)*size);
    int target = 0;
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 2) target = i;
    }


    // init
    int* visited = (int*) calloc(rows*cols, sizeof(int));


    // answer
    bfs(arr, rows, cols, visited, target);
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0 && arr[i] != 0) arr[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % cols == 0) printf("\n");
    }


    free(arr);
    free(visited);
    return 0;
}