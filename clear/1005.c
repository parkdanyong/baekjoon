/*
    title: ACM Craft
    tag: graph, dp, Topological Sorting, DAG (Directed Acyclic Graph)
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_COUNT 1000


typedef struct Node {
    int ver;
    struct Node* next;
}node;


typedef struct CircularQueue {
    int* arr;
    int size;
    int front;
    int rear;
}CQ;



int T;
int n, k, dest;
int* weight;
node** aList;
node** rear;


int max(int a, int b) {
    return a > b ? a : b;
}


node* createNode(int ver) {
    node* new = (node*) malloc(sizeof(node));
    new->ver = ver;
    new->next = NULL;
    return new;
}


CQ* createCQ(int size) {
    CQ* cq = (CQ*) malloc(sizeof(CQ));
    cq->arr = (int*) malloc(sizeof(int)*size);
    cq->size = size;
    cq->front = 0;
    cq->rear = 0;

    return cq;
}


void enqueue(CQ* cq, int ver) {
    int cmp = (cq->rear + 1) % cq->size;
    if (cq->front == cmp) return;

    cq->rear = cmp;
    cq->arr[cmp] = ver;
}


int dequeue(CQ* cq) {
    if (cq->front == cq->rear) return 0;

    cq->front = (cq->front + 1) % cq->size;
    return cq->arr[cq->front];
}


void addPath(int v1, int v2) {
    node* new = createNode(v2);
    if (rear[v1] == NULL) {
        aList[v1] = new;
        rear[v1] = new;
    }
    else {
        rear[v1]->next = new;
        rear[v1] = new;
    }
}


void clearList() {
    node* cur;
    node* del;
    for (int i = 1; i <= n; i++) {
        cur = aList[i];
        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);
        }
        aList[i] = NULL;
        rear[i] = NULL;
    }
}


void initList() {
    for (int i = 0; i <= MAX_COUNT; i++) {
        aList[i] = NULL;
        rear[i] = NULL;
    }
}


int dp() {
    CQ* cq = createCQ(n+1);
    int* mem = (int*) calloc(n+1, sizeof(int));
    int* inDeg = (int*) calloc(n+1, sizeof(int));
    node* cur;
    for (int i = 1; i <= n; i++) {
        cur = aList[i];
        while (cur) {
            inDeg[cur->ver] += 1;
            cur = cur->next;
        }
    }

    
    for (int i = 1; i <= n; i++) {
        if (inDeg[i] == 0) enqueue(cq, i);
    }
    int v;
    while (cq->front != cq->rear) {
        // pop
        v = dequeue(cq);

        // push
        cur = aList[v];
        while (cur) {
            mem[cur->ver] = max(mem[cur->ver], mem[v] + weight[v]);
            inDeg[cur->ver] -= 1;
            if (inDeg[cur->ver] == 0) enqueue(cq, cur->ver);
            cur = cur->next;
        }
    }
    
    
    int rev = mem[dest] + weight[dest];
    free(cq->arr);
    free(cq);
    free(mem);
    free(inDeg);
    return rev;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &T);
    // weight = (int*) malloc(sizeof(int)*(MAX_COUNT+1));
    // aList = (node**) malloc(sizeof(node*)*(MAX_COUNT+1));
    // rear = (node**) malloc(sizeof(node*)*(MAX_COUNT+1));
    // initList();
    // int ans, v1, v2;
    // for (int i = 0; i < T; i++) {
    //     fscanf(file, "%d %d", &n, &k);
    //     for (int j = 1; j <= n; j++) {
    //         fscanf(file, "%d", &weight[j]);
    //     }
    //     for (int j = 1; j <= k; j++) {
    //         fscanf(file, "%d %d", &v1, &v2);
    //         addPath(v1, v2);
    //     }
    //     fscanf(file, "%d", &dest);

    //     ans = dp();
    //     printf("%d\n", ans);
    //     clearList();
    // }
    // fclose(file);


    // input
    scanf("%d", &T);


    // init
    weight = (int*) malloc(sizeof(int)*(MAX_COUNT+1));
    aList = (node**) malloc(sizeof(node*)*(MAX_COUNT+1));
    rear = (node**) malloc(sizeof(node*)*(MAX_COUNT+1));
    initList();


    // answer
    int ans, v1, v2;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &n, &k);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &weight[j]);
        }
        for (int j = 1; j <= k; j++) {
            scanf("%d %d", &v1, &v2);
            addPath(v1, v2);
        }
        scanf("%d", &dest);

        ans = dp();
        printf("%d\n", ans);
        clearList();
    }



    free(weight);
    free(aList);
    free(rear);
    return 0;
}