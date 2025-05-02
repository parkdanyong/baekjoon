/*
    title: 그래프 탐색 2
    tag: gragh, BFS
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int pos;
    int count;
}Node;


int V, E, q, size;
int* arr;



typedef struct CircularQueue {
    Node* arr;
    int size;
    int front;
    int rear;
}CQ;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (Node*) malloc(sizeof(Node)*size);
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


Node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        Node tmp = {-1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}



void bfs() {
    int* visited = (int*) calloc(V+1, sizeof(int));
    visited[1] = 1;
    CQ* cq = createCQ(V+2);
    enqueue(cq, 1, 0);
    int* count = (int*) calloc(V+1, sizeof(int));


    Node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        // printf("pos: %d\n", cur.pos);


        // push
        for (int i = 2; i <= V; i++) {
            if (arr[(V+1)*cur.pos + i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                count[i] = cur.count + 1;
                enqueue(cq, i, cur.count+1);
            }
        }
    }


    printf("0 ");
    for (int i = 2; i <= V; i++) {
        if (count[i] == 0) printf("-1 ");
        else printf("%d ", count[i]);
    }
    printf("\n");


    free(visited);
    free(cq->arr);
    free(cq);
    free(count);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &V, &E);
    // size = (V + 1) * (V + 1);
    // arr = (int*) calloc(size, sizeof(int));
    // int v1, v2;
    // for (int i = 0; i < E; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     arr[(V+1)*v1 + v2] = 1;
    //     arr[(V+1)*v2 + v1] = 1;
    // }
    // fscanf(file, "%d", &q);
    // for (int i = 0; i < q; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     arr[(V+1)*v1 + v2] = 1;
    //     arr[(V+1)*v2 + v1] = 1;
    //     bfs();
    // }
    // fclose(file);


    // input
    scanf("%d %d", &V, &E);
    size = (V + 1) * (V + 1);
    arr = (int*) calloc(size, sizeof(int));
    int v1, v2;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &v1, &v2);
        arr[(V+1)*v1 + v2] = 1;
        arr[(V+1)*v2 + v1] = 1;
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d %d", &v1, &v2);
        arr[(V+1)*v1 + v2] = 1;
        arr[(V+1)*v2 + v1] = 1;
        bfs();
    }


    free(arr);
    return 0;
}