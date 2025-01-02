/* 
    title: 트리의 부모 찾기
    tag: data structure

    
    1. Edge List
    2. Adjacency List
    3. Adjacency Matrix

    I make Adjacency List from input and search by DFS.

*/



#include <stdio.h>
#include <stdlib.h>




typedef struct Node {
    int nodeNumber;
    struct Node* next;
}node;


node* createNode(int nodeNumber) {
    node* newNode = (node*) malloc(sizeof(node));
    newNode->nodeNumber = nodeNumber;
    newNode->next = NULL;

    return newNode;
}


node** createAL(int size) {
    node** AL = (node**) malloc(sizeof(node*)*size);
    for (int i = 0; i < size; i++) {
        AL[i] = NULL;
    }

    return AL;
}


void appendAdjacentNode(node** AL, int n1, int n2) {
    node* pre = NULL;
    node* cur = NULL;

    if (AL[n1-1] == NULL) {
        AL[n1-1] = createNode(n2);
    }
    else {
        cur = AL[n1-1];
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = createNode(n2);
    }

    if (AL[n2-1] == NULL) {
        AL[n2-1] = createNode(n1);
    }
    else {
        cur = AL[n2-1];
        while (cur) {   
            pre = cur;
            cur = cur->next;
        }
        pre->next = createNode(n1);
    }
}


void DFS(node** AL, int size, int* parentArr) {
    int* visited = (int*) calloc(size, sizeof(int));
    visited[0] = 1; // root is always visited

    int* stack = (int*) malloc(sizeof(int)*size);
    stack[0] = 1;
    int top = 0;

    int cur = 0;

    node* tmp;
    int flag = 1;
    while (top != -1 || flag != 1) {
        if (flag == 1) { // pop
            cur = stack[top--];
        }

        parentArr[cur-1] = stack[top];
        flag = 1;
        visited[cur-1] = 1;
        tmp = AL[cur-1];
        while (tmp) {
            if (visited[tmp->nodeNumber - 1] == 0) {
                stack[++top] = cur; // push
                cur = tmp->nodeNumber;
                flag = 0;
                break;
            }
            tmp = tmp->next;
        }
    }

    free(stack);
    free(visited);
}




void printAL(node** AL, int size) {
    node* cur;
    node* next;

    for (int i = 0; i < size; i++) {
        cur = AL[i];
        printf("%d: ", i + 1);
        while (cur) {
            next = cur->next;
            printf("%d ", cur->nodeNumber);
            cur = next;
        }
        printf("\n");
    }
}


void freeAll(node** AL, int size) {
    node* cur;
    node* next;

    for (int i = 0; i < size; i++) {
        cur = AL[i];
        while (cur) {
            next = cur->next;
            free(cur);
            cur = next;
        }
    }
    
    free(AL);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    

    // input
    int size = 0;
    // fscanf(file, "%d", &size);
    scanf("%d", &size);
    node** AL = createAL(size);

    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < size-1; i++) {
        // fscanf(file, "%d %d", &n1, &n2);
        scanf("%d %d", &n1, &n2);
        appendAdjacentNode(AL, n1, n2);
    }

    
    // output
    // printAL(AL, size);
    int* parentArr = (int*) calloc(size, sizeof(int));
    DFS(AL, size, parentArr);
    for (int i = 1; i < size; i++) {
        printf("%d\n", parentArr[i]);
    }
    

    freeAll(AL, size);
    free(parentArr);

    return 0;
}