/*
    title: 트리의 지름
    tag: graph, DFS
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int ver;
    int weight;
    struct Node* next;
}node;


int n;
node** arr;
node** rear;


void addPath(int v1, int v2, int w) {
    node* new = (node*) malloc(sizeof(node));
    new->ver = v2;
    new->weight = w;
    new->next = NULL;
    if (rear[v1] == NULL) {
        arr[v1] = new;
        rear[v1] = new;
    }
    else {
        rear[v1]->next = new;
        rear[v1] = new;
    }
}


node dfs(int v) {
    int* visited = (int*) calloc(n+1, sizeof(int));
    visited[v] = 1;
    node* stack = (node*) malloc(sizeof(node)*(n+1));
    stack[0].ver = v;
    stack[0].weight = 0;
    int top = 0;

    node furest = {0, 0, NULL};
    node* child;
    node cur;
    while (top != -1) {
        // pop
        cur = stack[top--];
        if (furest.weight < cur.weight) furest = cur;


        // push
        child = arr[cur.ver];
        while (child) {
            if (visited[child->ver] == 0) {
                top += 1;
                stack[top].ver = child->ver;
                stack[top].weight = cur.weight + child->weight;
                visited[child->ver] = 1;
            }
            child = child->next;
        }
    }

    
    free(visited);
    free(stack);
    return furest;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (node**) malloc(sizeof(node*)*(n+1));
    // rear = (node**) malloc(sizeof(node*)*(n+1));
    // for (int i = 0; i <= n; i++) {
    //     arr[i] = NULL;
    //     rear[i] = NULL;
    // }
    // int v1, v2, w;
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d", &v1);
    //     while (1) {
    //         fscanf(file, "%d", &v2);
    //         if (v2 == -1) break;
    //         fscanf(file, "%d", &w);
    //         addPath(v1, v2, w);
    //     }
    // }   
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (node**) malloc(sizeof(node*)*(n+1));
    rear = (node**) malloc(sizeof(node*)*(n+1));
    for (int i = 0; i <= n; i++) {
        arr[i] = NULL;
        rear[i] = NULL;
    }
    int v1, v2, w;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v1);
        while (1) {
            scanf("%d", &v2);
            if (v2 == -1) break;
            scanf("%d", &w);
            addPath(v1, v2, w);
        }
    }   


    // answer
    node ver = dfs(1);
    ver = dfs(ver.ver);
    printf("%d\n", ver.weight);


    node* tmp;
    node* del;
    for (int i = 0; i <= n; i++) {
        del = arr[i];
        while (del) {
            tmp = del->next;
            free(del);
            del = tmp;
        }
    }
    free(arr);
    free(rear);
    return 0;
}