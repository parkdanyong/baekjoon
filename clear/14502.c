/*
    title: 연구소
    tag: graph, BFS, brute force
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_VIRUS 10


int rows, cols, size;
int* arr;
int* virus;
int v_count;
int space;


int max(int a, int b) {
    return a > b ? a : b;
}


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int pos) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = pos;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return -1;

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


int bfs(int w1, int w2, int w3) {
    int* visited = (int*) calloc(size, sizeof(int));
    CQ* cq = createCQ(size+1);
    visited[w1] = 1;
    visited[w2] = 1;
    visited[w3] = 1;
    for (int i = 0; i < v_count; i++) {
        visited[virus[i]] = 1;
        enqueue(cq, virus[i]);
    }
    

    int newSpace = space - 3;
    int cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);


        // push
        if (cur + 1 < size && cur % cols + 1 < cols) { // right
            if (arr[cur + 1] == 0 && visited[cur + 1] == 0) {
                visited[cur + 1] = 1;
                enqueue(cq, cur + 1);
                newSpace -= 1;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (arr[cur - 1] == 0 && visited[cur - 1] == 0) {
                visited[cur - 1] = 1;
                enqueue(cq, cur - 1);
                newSpace -= 1;
            }
        }
        if (cur + cols < size) { // down
            if (arr[cur + cols] == 0 && visited[cur + cols] == 0) {
                visited[cur + cols] = 1;
                enqueue(cq, cur + cols);
                newSpace -= 1;
            }
        }
        if (0 <= cur - cols) { // up
            if (arr[cur - cols] == 0 && visited[cur - cols] == 0) {
                visited[cur - cols] = 1;
                enqueue(cq, cur - cols);
                newSpace -= 1;
            }
        }
    }
    

    free(cq->arr);
    free(cq);
    free(visited);
    return newSpace;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // virus = (int*) malloc(sizeof(int)*MAX_VIRUS);
    // v_count = 0;
    // space = 0;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 0) space += 1;
    //     else if (arr[i] == 2) virus[v_count++] = i;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    virus = (int*) malloc(sizeof(int)*MAX_VIRUS);
    v_count = 0;
    space = 0;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 0) space += 1;
        else if (arr[i] == 2) virus[v_count++] = i;
    }


    // answer
    int cmp;
    int ans = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            for (int k = j+1; k < size; k++) {
                if (arr[i] == 0 && arr[j] == 0 && arr[k] == 0) {
                    cmp = bfs(i, j, k);
                    ans = max(ans, cmp);
                }
            }
        }
    }
    printf("%d\n", ans);


    free(arr);
    free(virus);
    return 0;
}