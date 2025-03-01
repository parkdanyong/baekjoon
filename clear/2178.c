/*
    title: 미로 탐색
    tag: graph, BFS

    
    BFS guarantees that the first path visited to the end is the shortest one, but DFS is not. 
    Using BFS once is enough to find the shortest path, but you have to find all path can reach the end if you use DFS.

*/




#include <stdio.h>
#include <stdlib.h>




typedef struct Maze {
    int* map;
    int rows;
    int cols;
}maze;


typedef struct Node {
    int pos;
    int count;
}node;


typedef struct CirclarQueue {
    node* queue;
    int size;
    int front;
    int rear;
}CQ;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->queue = (node*) malloc(sizeof(node)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;
    
    return cq;
}


void enqueue(CQ* cq, int pos, int count) {
    int tmp = (cq->rear + 1) % cq->size;
    if (cq->front == tmp) return;
    
    cq->rear = tmp;
    cq->queue[cq->rear].pos = pos;
    cq->queue[cq->rear].count = count;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) return (node) {-1, -1};
    
    cq->front = (cq->front + 1) % cq->size;
    return cq->queue[cq->front];
}


void move(maze* myMaze, CQ* cq, int pos, int count) {
    int mazeField = myMaze->rows * myMaze->cols;
    int cols = myMaze->cols;
    int row = (int) pos / cols;


    if (pos + 1 < mazeField && (int) ((pos + 1) / cols) == row && myMaze->map[pos + 1] == 1) {
        myMaze->map[pos + 1] = 0; 
        enqueue(cq, pos + 1, count); // move right
    }
    if (pos + cols < mazeField && myMaze->map[pos + cols] == 1) {
        myMaze->map[pos + cols] = 0; 
        enqueue(cq, pos + cols, count); // move down}
    }
    if (0 <= pos - 1 && (int) ((pos - 1) / cols) == row && myMaze->map[pos - 1] == 1) {
        myMaze->map[pos - 1] = 0;
        enqueue(cq, pos - 1, count); // move left
    }
    if (0 <= pos - cols && myMaze->map[pos - cols] == 1) {
        myMaze->map[pos - cols] = 0;
        enqueue(cq, pos - cols, count); // move up}
    }
}


int BFS(maze* myMaze) {
    CQ* cq = createCQ(myMaze->rows * myMaze->cols + 1);
    node cur;
    enqueue(cq, 0, 1);
    int fin = myMaze->rows * myMaze->cols - 1;


    while (1) {
        cur = dequeue(cq);
        // printf("pos: %d count: %d\n", cur.pos, cur.count);
        if (cur.pos == fin) break;
        if (cur.pos == -1) break;
        // myMaze->map[cur.pos] = 0; // visited
        cur.count++;
        move(myMaze, cq, cur.pos, cur.count);
    }

    free(cq->queue);
    free(cq);

    return cur.count;
}


void printMap(maze myMaze) {
    int rows = myMaze.rows;
    int cols = myMaze.cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d", myMaze.map[i*cols + j]);
        }
        printf("\n");
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int rows, cols; 
    // fscanf(file, "%d %d", &rows, &cols);
    // int* m = (int*) malloc(sizeof(int)*rows*cols);
    // char* tmp = (char*) malloc(sizeof(char)*(cols + 1));
    // for (int i = 0; i < rows; i++) {
    //     // fscanf(file, "%s", tmp);
    //     for (int j = 0; j < cols; j++) {
    //         // m[i*cols + j] = tmp[j] - 48;
    //         fscanf(file, "%1d", &m[i*cols + j]);
    //     }
    // }
    // maze myMaze = {m, rows, cols};
    // fclose(file);


    // input
    int rows, cols; 
    scanf("%d %d", &rows, &cols);
    int* m = (int*) malloc(sizeof(int)*rows*cols);
    char* tmp = (char*) malloc(sizeof(char)*(cols + 1));
    for (int i = 0; i < rows; i++) {
        scanf("%s", tmp);
        for (int j = 0; j < cols; j++) {
            m[i*cols + j] = tmp[j] - 48;
            // scanf("%1d", &m[i*cols + j]);
        }
    }
    maze myMaze = {m, rows, cols};


    // answer
    int ans = BFS(&myMaze);
    printf("%d\n", ans);



    free(m);
    free(tmp);
    return 0;
}