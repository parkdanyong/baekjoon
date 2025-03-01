/*
    title: DSLR
    tag: graph, BFS
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_SIZE 10010


typedef struct Node {
    int state;
    int pre;
    char cmd;
}node;


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;


char* ans;
node* visited;


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int val) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = val;
}


// int computeCommand(int val, char cmd) {
//     if (cmd == 'D') return val * 2 % 10000;  
//     else if (cmd == 'S') return val == 0 ? 9999 : val - 1;
//     else if (cmd == 'L') {
//         int numDigits = 4;
//         int tmp = 1000;
//         for (int i = 0; i < 3; i++) {
//             if (val / tmp != 0) break;
//             numDigits -= 1;
//             tmp /= 10;
//         }

//         tmp = pow(10, numDigits - 1);
//         int result = val % tmp * 10 + val / tmp % 10; 
//         return result;
//     }
//     else if (cmd == 'R') {
//         int numDigits = 4;
//         int tmp = 1000;
//         for (int i = 0; i < 3; i++) {
//             if (val / tmp != 0) break;
//             numDigits -= 1;
//             tmp /= 10;
//         }

//         tmp = pow(10, numDigits - 1);
//         int result = val % 10 * tmp + val / 10; 
//         return result;
//     }
// }


int computeCommand(int val, char cmd) {
    if (cmd == 'D') return val * 2 % 10000;  
    else if (cmd == 'S') return val == 0 ? 9999 : val - 1;
    else if (cmd == 'L') return  (val * 10) % 10000 + (val / 1000);
    else if (cmd == 'R') return (val / 10) + (val % 10) * 1000;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) {
        return -1;
    }

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


void record(int val, int pre, char cmd) {
    visited[val].state = 1;
    visited[val].pre = pre;
    visited[val].cmd = cmd;
}


int bfs(int a, int b) {
    CQ* cq = createCQ(MAX_SIZE + 10);
    enqueue(cq, a);
    record(a, -1, 'B');

    int val;
    int cur;
    while (cq->front != cq->rear) {
        // pop
        cur = dequeue(cq);
        if (cur == b) break;
        
        // init
        val = computeCommand(cur, 'D');
        if (visited[val].state == 0) {
            enqueue(cq, val);
            record(val, cur, 'D');
        }
        val = computeCommand(cur, 'S');
        if (visited[val].state == 0) {
            enqueue(cq, val);
            record(val, cur, 'S');
        }
        val = computeCommand(cur, 'L');
        if (visited[val].state == 0) {
            enqueue(cq, val);
            record(val, cur, 'L');
        }
        val = computeCommand(cur, 'R');
        if (visited[val].state == 0) {
            enqueue(cq, val);
            record(val, cur, 'R');
        }
    }

    free(cq->arr);
    free(cq);
    return cur;
}


void goBack(int start) {
    int cur = start;
    int i = 0;
    while (visited[cur].cmd != 'B') {
        ans[i++] = visited[cur].cmd;
        cur = visited[cur].pre;
    }
    for (i -= 1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n");
}


int main() {
    // input
    int t;
    scanf("%d", &t);
    int a, b;


    // init
    visited = (node*) calloc(MAX_SIZE, sizeof(node));


    // answer
    ans = (char*) calloc(MAX_SIZE, sizeof(char));
    int B;
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &a, &b);
        B = bfs(a, b);
        goBack(B);
        memset(visited, 0, sizeof(node)*MAX_SIZE);
        memset(ans, 0, sizeof(char)*MAX_SIZE);
    }


    free(ans);
    free(visited);
    return 0;
}