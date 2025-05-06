/*
    title: A와 B
    tag: 

    https://www.acmicpc.net/board/view/83783
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STR_LEN 1010


typedef struct Dequeue {
    char* arr;
    int size;
    int front;
    int rear;
    int reverse;
}Dequeue;



char S[MAX_STR_LEN];
Dequeue* T;


Dequeue* createDequeue(int size) {
    Dequeue* deque = (Dequeue*) malloc(sizeof(Dequeue));
    deque->arr = (char*) malloc(sizeof(char)*size);
    deque->size = size;
    deque->front = 0;
    deque->rear = 0;
    deque->reverse = 0;
    return deque;
}


void addRear(Dequeue* deque, char val) {
    int cmp = (deque->rear + 1) % deque->size;
    if (deque->front == cmp) return; // full

    deque->rear = cmp;
    deque->arr[cmp] = val;
}


char deleteFront(Dequeue* deque) {
    if (deque->front == deque->rear) return '0'; // empty

    deque->front = (deque->front + 1) % deque->size;
    return deque->arr[deque->front];
}


char deleteRear(Dequeue* deque) {
    if (deque->front == deque->rear) return '0'; // empty

    char rv = deque->arr[deque->rear];
    deque->rear = (deque->size + deque->rear - 1) % deque->size;
    return rv;
}


char* makeStr(Dequeue* deqeu, int len) {
    char* str = (char*) malloc(sizeof(char)*(len+1));
    if (deqeu->reverse) {
        for (int i = 0; i < len; i++) {
            str[i] = deleteRear(deqeu);
        }
    }
    else {
        for (int i = 0; i < len; i++) {
            str[i] = deleteFront(deqeu);
        }
    }
    str[len] = '\0';
    return str;
}



int main() {
    // input
    scanf("%s", S);
    int S_len = strlen(S);
    if (S[S_len - 2] == '\n') {
        S[S_len - 2] = '\0';
        S_len -= 1;
    }
    getchar();

    T = createDequeue(MAX_STR_LEN);
    int T_len = 0;
    char c;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') break;
        addRear(T, c);
        T_len += 1;
    }
    
    

    // answer
    while (S_len < T_len) {
        if (T->reverse) {
            if (T->arr[T->front+1] == 'B') T->reverse = (T->reverse + 1) % 2;
            deleteFront(T);
        }
        else {
            if (T->arr[T->rear] == 'B') T->reverse = (T->reverse + 1) % 2;
            deleteRear(T);
        }
        T_len -= 1;
    }
    char* str = makeStr(T, T_len);
    int ans = 0;
    if (strcmp(S, str) == 0) ans = 1;
    printf("%d\n", ans);
    

    free(T->arr);
    free(T);
    free(str);
    return 0;
}