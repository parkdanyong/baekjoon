/*
    title: 열쇠 
    tag: graph, BFS, DFS
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 10000


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;




int T, rows, cols, size;
char* arr;
int* keys;
CQ* queue;
int* visited;
CQ* keep; 




CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void initCQ(CQ* cq) {
    cq->front = 0;
    cq->rear = 0;
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


int getCount(CQ* cq) {
    if (cq->front <= cq->rear) return cq->rear - cq->front;
    else return cq->size + cq->rear - cq->front;
}


int isDoor(char c) {
    if ('A' <= c && c <= 'Z') return 1;
    return 0;
}


int hasKey(char c) {
    if (keys[c - 'A'] == 1) return 1;
    else return 0;
}


int isKey(char c) {
    if ('a' <= c && c <= 'z') return 1;
    return 0;
}


void addKey(char c) {
    keys[c - 'a'] = 1;
}


void move(int pos) {
    if (isDoor(arr[pos]) && !hasKey(arr[pos])) {
        visited[pos] = 2; // keep
        enqueue(keep, pos);
    }
    else {
        visited[pos] = 1;
        enqueue(queue, pos);
    }
}


int searchKeep() {
    int repeat = getCount(keep);
    int pos = 0;
    for (int i = 0; i < repeat; i++) {
        pos = dequeue(keep);
        if (hasKey(arr[pos])) {
            visited[pos] = 1; // visit
            return pos;
        }
        enqueue(keep, pos);
    }
    return -1;
}


int bfs(int pos) {
    initCQ(queue);
    enqueue(queue, pos);
    visited[pos] = 1;
    

    int paper = 0;
    int cur;
    while (1) {
        // pop
        if (queue->front == queue->rear) {
            cur = searchKeep();
            if (cur == -1) break;
        }
        else cur = dequeue(queue);
        // printf("pos: %d\n", cur);


        if (isKey(arr[cur])) addKey(arr[cur]);
        else if (arr[cur] == '$') paper += 1;
        arr[cur] = '.';
        

        // push
        if (cur + 1 < size && cur % cols + 1 < cols) { // right
            if (arr[cur + 1] != '*' && visited[cur + 1] == 0) move(cur + 1);
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (arr[cur - 1] != '*' && visited[cur - 1] == 0) move(cur - 1);
        }
        if (0 <= cur - cols) { // up
            if (arr[cur - cols] != '*' && visited[cur - cols] == 0) move(cur - cols);
        }
        if (cur + cols < size) { // down
            if (arr[cur + cols] != '*' && visited[cur + cols] == 0) move(cur + cols);
        }
    }
    return paper;
}


int getStartPos() {
    for (int i = 0; i < cols; i++) {
        if (arr[i] != '*' && visited[i] != 1) {
            if (isDoor(arr[i])) {
                if (hasKey(arr[i])) return i; 
            } 
            else return i; 
        }
        if (arr[cols*(rows-1) + i] != '*' && visited[cols*(rows-1) + i] != 1) {
            if (isDoor(arr[cols*(rows-1) + i])) {
                if (hasKey(arr[cols*(rows-1) + i])) return cols*(rows-1) + i;
            }
            else return cols*(rows-1) + i;
        }    
    }
    for (int i = 1; i < rows-1; i++) {
        if (arr[cols * i] != '*' && visited[cols * i] != 1) {
            if (isDoor(arr[cols * i])) {
                if (hasKey(arr[cols * i])) return cols * i;
            }
            else return cols * i;
        }
        if (arr[cols * i + cols - 1] != '*' && visited[cols * i + cols - 1] != 1) {
            if (isDoor(arr[cols * i + cols - 1])) {
                if (hasKey(arr[cols * i + cols - 1])) return cols * i + cols - 1;
            }
            else return cols * i + cols - 1;
        }
    }
    return -1;
}



int main() {
    // init
    queue = createCQ(MAX_SIZE+1);
    visited = (int*) malloc(sizeof(int)*MAX_SIZE);
    keep = createCQ(MAX_SIZE+1); 
    arr = (char*) malloc(sizeof(char)*MAX_SIZE); 
    keys = (int*) malloc(sizeof(int)*26); 


    int start;
    char k[50];
    int len;
    int ans = 0;


    // input
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &rows, &cols);


        size = rows * cols;
        initCQ(keep);
        memset(visited, 0, sizeof(int)*MAX_SIZE);
        memset(keys, 0, sizeof(int)*26);


        for (int i = 0; i < size; i++) {
            scanf("%c", &arr[i]);
            if (arr[i] == '\n') i -= 1;
        }
        scanf("%s", k);
        if (k[0] != '0') {
            len = strlen(k);
            for (int i = 0; i < len; i++) {
                addKey(k[i]);
            }
        }


        // answer
        ans = 0;
        while (1) {
            start = getStartPos();
            if (start == -1) break;
            ans += bfs(start);
        }
        printf("%d\n", ans);
    }


    // input
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &T);
    // for (int t = 0; t < T; t++) {
    //     fscanf(file, "%d %d", &rows, &cols);


    //     size = rows * cols;
    //     initCQ(keep);
    //     memset(visited, 0, sizeof(int)*MAX_SIZE);
    //     memset(keys, 0, sizeof(int)*26);


    //     for (int i = 0; i < size; i++) {
    //         fscanf(file, "%c", &arr[i]);
    //         if (arr[i] == '\n') i -= 1;
    //     }
    //     fscanf(file, "%s", k);
    //     if (k[0] != '0') {
    //         len = strlen(k);
    //         for (int i = 0; i < len; i++) {
    //             addKey(k[i]);
    //         }
    //     }


    //     // answer
    //     ans = 0;
    //     while (1) {
    //         start = getStartPos();
    //         if (start == -1) break;
    //         ans += bfs(start);
    //     }
    //     printf("%d\n", ans);
    // }
    // fclose(file);


    free(arr);
    free(keys);
    free(queue->arr);
    free(queue);
    free(visited);
    free(keep->arr);
    free(keep);
    return 0;
}