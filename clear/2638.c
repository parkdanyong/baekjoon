/*
    title: 치즈
    tag: graph, BFS, DFS
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;


int rows, cols, size;
int* arr;
CQ* cq;


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


void dfs() {
    int* visited = (int*) calloc(size, sizeof(int));
    visited[0] = 1;
    int* stack = (int*) malloc(sizeof(int)*size);
    stack[0] = 0;
    int top = 0;
    arr[0] = 2;

    int cur;
    while (top != -1) {
        // pop
        cur = stack[top--];

        // push
        if (cur + 1 < size && cur % cols + 1 < cols) { // right
            if (arr[cur + 1] != 1 && visited[cur + 1] == 0) {
                visited[cur + 1] = 1;
                arr[cur + 1] = 2;
                stack[++top] = cur + 1;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (arr[cur - 1] != 1 && visited[cur - 1] == 0) {
                visited[cur - 1] = 1;
                arr[cur - 1] = 2;
                stack[++top] = cur - 1;
            }
        }
        if (cur + cols < size) { // down
            if (arr[cur + cols] != 1 && visited[cur + cols] == 0) {
                visited[cur + cols] = 1;
                arr[cur + cols] = 2;
                stack[++top] = cur + cols;
            }
        }
        if (0 <= cur - cols) { // up
            if (arr[cur - cols] != 1 && visited[cur - cols] == 0) {
                visited[cur - cols] = 1;
                arr[cur - cols] = 2;
                stack[++top] = cur - cols;
            }
        }
    }


    free(visited);
    free(stack);
}


int isMelted(int pos) {
    int count = 0;
    if (pos + 1 < size && pos % cols + 1 < cols) { // right
        if (arr[pos + 1] == 2) count += 1;
    }
    if (0 <= pos - 1 && 0 <= pos % cols - 1) { // left
        if (arr[pos - 1] == 2) count += 1;
    }
    if (pos + cols < size) { // down
        if (arr[pos + cols] == 2) count += 1;
    }
    if (0 <= pos - cols) { // up
        if (arr[pos - cols] == 2) count += 1;
    }
    
    if (count >= 2) return 1;
    else return 0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (int*) malloc(sizeof(int)*size);
    // cq = createCQ(size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == 1) enqueue(cq, i);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (int*) malloc(sizeof(int)*size);
    cq = createCQ(size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == 1) enqueue(cq, i);
    }


    // answer
    int cheeze;
    int n = 0;
    int ans = 0;
    while (cq->front != cq->rear) {
        dfs();
        if (cq->front < cq->rear) n = cq->rear - cq->front;
        else n = (cq->size - (cq->front - cq->rear));
        for (int i = 0; i < n; i++) {
            cheeze = dequeue(cq);
            if (isMelted(cheeze)) arr[cheeze] = 0;
            else enqueue(cq, cheeze);
        }
        ans += 1;
    }
    printf("%d\n", ans);


    free(arr);
    free(cq->arr);
    free(cq);
    return 0;
}