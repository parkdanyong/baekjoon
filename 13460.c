/*
    title: 구슬 탈출 2
    tag: graph, BFS
*/



#include <stdio.h>
#include <stdlib.h>


#define GOAL 1000



typedef struct Node {
    int R_pos;
    int B_pos;
    int count;
}node;


typedef struct CircularQueue {
    node* arr;
    int size;
    int front;
    int rear;
}CQ;




int rows, cols, size;
char* arr;




CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (node*) malloc(sizeof(node)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int R, int B, int count) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp].R_pos = R;
    cq->arr[cmp].B_pos = B;
    cq->arr[cmp].count = count;
}


node dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        node tmp = {-1, -1, -1};
        return tmp;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


node move(node cur, char direction) {
    if (direction == 'L') {
        while (1) {
            if (cur.R_pos % cols < cur.B_pos % cols) {
                if (0 <= cur.R_pos - 1 && 0 <= cur.R_pos % cols - 1) {
                    if (arr[cur.R_pos - 1] == '.') cur.R_pos -= 1;
                    else if (arr[cur.R_pos - 1] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
                if (0 <= cur.B_pos - 1 && 0 <= cur.B_pos % cols - 1) {
                    if (arr[cur.B_pos - 1] == '.') cur.B_pos -= 1;
                    else if (arr[cur.B_pos - 1] == 'O') cur.B_pos = GOAL;
                }
            }
            else {
                if (0 <= cur.B_pos - 1 && 0 <= cur.B_pos % cols - 1) {
                    if (arr[cur.B_pos - 1] == '.') cur.B_pos -= 1;
                    else if (arr[cur.B_pos - 1] == 'O') cur.B_pos = GOAL;
                }
                if (0 <= cur.R_pos - 1 && 0 <= cur.R_pos % cols - 1) {
                    if (arr[cur.R_pos - 1] == '.') cur.R_pos -= 1;
                    else if (arr[cur.R_pos - 1] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
            }
        }
    }
    else if (direction == 'R') {
        while (1) {
            if (cur.R_pos % cols > cur.B_pos % cols) {
                if (cur.R_pos + 1 < size && cur.R_pos % cols + 1 < size) {
                    if (arr[cur.R_pos + 1] == '.') cur.R_pos += 1;
                    else if (arr[cur.R_pos + 1] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
                if (cur.B_pos + 1 < size && cur.B_pos % cols + 1 < size) {
                    if (arr[cur.B_pos + 1] == '.') cur.B_pos += 1;
                    else if (arr[cur.B_pos + 1] == 'O') cur.B_pos = GOAL;
                }
            }
            else {
                printf("good\n");
                if (cur.B_pos + 1 < size && cur.B_pos % cols + 1 < size) {
                    if (arr[cur.B_pos + 1] == '.') cur.B_pos += 1;
                    else if (arr[cur.B_pos + 1] == 'O') cur.B_pos = GOAL;
                }
                if (cur.R_pos + 1 < size && cur.R_pos % cols + 1 < size) {
                    if (arr[cur.R_pos + 1] == '.') cur.R_pos += 1;
                    else if (arr[cur.R_pos + 1] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
            }
        }
    }
    else if (direction == 'U') {
        while (1) {
            if (cur.R_pos < cur.B_pos) {
                if (0 <= cur.R_pos - cols) {
                    if (arr[cur.R_pos - cols] == '.') cur.R_pos -= cols;
                    else if (arr[cur.R_pos - cols] == 'O') cur.R_pos = GOAL;
                    else break;
                } 
                else break; 
                if (0 <= cur.B_pos - cols) {
                    if (arr[cur.B_pos - cols] == '.') cur.B_pos -= cols;
                    else if (arr[cur.B_pos - cols] == 'O') cur.B_pos = GOAL;
                }
            }
            else {
                if (0 <= cur.B_pos - cols) {
                    if (arr[cur.B_pos - cols] == '.') cur.B_pos -= cols;
                    else if (arr[cur.B_pos - cols] == 'O') cur.B_pos = GOAL;
                }
                if (0 <= cur.R_pos - cols) {
                    if (arr[cur.R_pos - cols] == '.') cur.R_pos -= cols;
                    else if (arr[cur.R_pos - cols] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break; 
            }
        }
    }
    else if (direction == 'D') {
        while (1) {
            if (cur.R_pos > cur.B_pos) {
                if (cur.R_pos + cols < size) {
                    if (arr[cur.R_pos + cols] == '.') cur.R_pos += cols;
                    else if (arr[cur.R_pos + cols] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
                if (cur.B_pos + cols < size) {
                    if (arr[cur.B_pos + cols] == '.') cur.B_pos += cols;
                    else if (arr[cur.B_pos + cols] == 'O') cur.B_pos = GOAL;
                }
            }
            else {
                if (cur.B_pos + cols < size) {
                    if (arr[cur.B_pos + cols] == '.') cur.B_pos += cols;
                    else if (arr[cur.B_pos + cols] == 'O') cur.B_pos = GOAL;
                }
                if (cur.R_pos + cols < size) {
                    if (arr[cur.R_pos + cols] == '.') cur.R_pos += cols;
                    else if (arr[cur.R_pos + cols] == 'O') cur.R_pos = GOAL;
                    else break;
                }
                else break;
            }
        }
    }
    return cur;
}


int bfs(int R, int B) {
    CQ* cq = createCQ(size+1);
    enqueue(cq, R, B, 0);
    int* visited = (int*) calloc(size, sizeof(int));
    visited[R] = 1;


    node tmp;
    int count = -1;
    node cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        printf("R: %d B: %d count: %d\n", cur.R_pos, cur.B_pos, cur.count);
        if (cur.R_pos == GOAL && cur.B_pos != GOAL) {
            count = cur.count;
            break;
        }


        // left
        tmp = move(cur, 'L');
        if (tmp.R_pos != cur.R_pos && visited[tmp.B_pos]) {
            visited[tmp.R_pos] = 1;
            enqueue(cq, tmp.R_pos, tmp.B_pos, cur.count + 1);
        }
        // right
        tmp = move(cur, 'R');
        if (tmp.R_pos != cur.R_pos && visited[tmp.B_pos]) {
            visited[tmp.R_pos] = 1;
            enqueue(cq, tmp.R_pos, tmp.B_pos, cur.count + 1);
        }
        // up
        tmp = move(cur, 'U');
        if (tmp.R_pos != cur.R_pos && visited[tmp.B_pos]) {
            visited[tmp.R_pos] = 1;
            enqueue(cq, tmp.R_pos, tmp.B_pos, cur.count + 1);
        }
        // down
        tmp = move(cur, 'D');
        if (tmp.R_pos != cur.R_pos && visited[tmp.B_pos]) {
            visited[tmp.R_pos] = 1;
            enqueue(cq, tmp.R_pos, tmp.B_pos, cur.count + 1);
        }
    }


    free(cq->arr);
    free(cq);
    free(visited);
    return count;
}




int main() {
    FILE* file = fopen("inputFile.txt", "r");
    fscanf(file, "%d %d %d", &rows, &cols);
    size = rows * cols;
    arr = (char*) malloc(sizeof(char)*size);
    int R, B;
    for (int i = 0; i < size; i++) {
        fscanf(file, "%c", &arr[i]);
        if (arr[i] == '\n') {
            i -= 1;
            continue;
        }
        if (arr[i] == 'R') {
            arr[i] = '.';
            R = i;
        }
        else if (arr[i] == 'B') {
            arr[i] = '.';
            B = i;
        }
    }
    fclose(file);


    // answer
    int ans = bfs(R, B);


    free(arr);
    return 0;
}