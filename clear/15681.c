/*
    title: 트리와 쿼리
    tag: graph, tree, DFS, dp
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int ver;
    int relation; // 0 child, 1 parent
    struct Node* next;
}node;


int N, R, Q;
node** tree;
node** rear;
int* mem;


node* createNode(int v) {
    node* new = (node*) malloc(sizeof(node));
    new->ver = v;
    new->relation = 0;
    new->next = NULL;
    return new;
}


void addPath(int v1, int v2) {
    node* to_2 = createNode(v2);
    node* to_1 = createNode(v1);


    if (rear[v1] == NULL) {
        tree[v1] = to_2;
        rear[v1] = to_2;
    }
    else {
        rear[v1]->next = to_2;
        rear[v1] = to_2;
    }

    if (rear[v2] == NULL) {
        tree[v2] = to_1;
        rear[v2] = to_1;
    }
    else {
        rear[v2]->next = to_1;
        rear[v2] = to_1;
    }
}


void makeTree(int currentNode, int parentNode) {
    node* cur = tree[currentNode];
    while (cur) {
        if (cur->ver != parentNode) {
            cur->relation = 0;
            makeTree(cur->ver, currentNode);
        }
        else {
            // printf("I'm %d, %d is my parrent node.\n", currentNode, cur->ver);
            cur->relation = 1;
        }
        cur = cur->next;
    }
}


void countSubtreeNodes(int currentNode) {
    mem[currentNode] = 1;
    node* cur = tree[currentNode];
    while (cur) {
        if (cur->relation != 1) {
            countSubtreeNodes(cur->ver);
            mem[currentNode] += mem[cur->ver];
        }
        cur = cur->next;
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &N, &R, &Q);
    // tree = (node**) malloc(sizeof(node*)*(N+1));
    // rear = (node**) malloc(sizeof(node*)*(N+1));
    // for (int i = 0; i <= N; i++) {
    //     tree[i] = NULL;
    //     rear[i] = NULL;
    // }
    // int v1, v2;
    // for (int i = 1; i < N; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     addPath(v1, v2);
    // }


    // input
    scanf("%d %d %d", &N, &R, &Q);
    tree = (node**) malloc(sizeof(node*)*(N+1));
    rear = (node**) malloc(sizeof(node*)*(N+1));
    for (int i = 0; i <= N; i++) {
        tree[i] = NULL;
        rear[i] = NULL;
    }
    int v1, v2;
    for (int i = 1; i < N; i++) {
        scanf("%d %d", &v1, &v2);
        addPath(v1, v2);
    }


    // init
    mem = (int*) calloc(N+1, sizeof(int));
    makeTree(R, -1);
    countSubtreeNodes(R);


    // answer
    int q = 0;
    for (int i = 0; i < Q; i++) {
        // fscanf(file, "%d", &q);
        scanf("%d", &q);
        printf("%d\n", mem[q]);
    }


    node* cur;
    node* del;
    for (int i = 0; i <= N; i++) {
        cur = tree[i];
        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);
        }
    }
    free(tree);
    free(rear);
    free(mem);
    // fclose(file);
    return 0;
}
