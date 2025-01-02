/* 
    title: 트리의 부모 찾기
    tag: data structure

    
    1. Edge List
    2. Adjacency List
    3. Adjacency Matrix

    I make Adjacency List from input and set parent-array by DFS.

*/



#include <stdio.h>
#include <stdlib.h>




typedef struct Node {
    int nodeNumber;
    node* next;
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

    if (AL[n1] == NULL) {
        AL[n1] = createNode(n2);
    }
    else {
        cur = AL[n1];
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = createNode(n2);
    }

    if (AL[n2] == NULL) {
        AL[n2] = createNode(n1);
    }
    else {
        cur = AL[n2];
        while (cur) {
            pre = cur;
            cur = cur->next;
        }
        pre->next = createNode(n1);
    }
}



int main() {
    



    return 0;
}