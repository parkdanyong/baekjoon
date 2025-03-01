/*
    title: 트리의 지름
    tag: graph, DFS

    DFS(root) -> find the furthest node A from root
    DFS(A) -> find the furthest node B from A
*/


#include <stdio.h>
#include <stdlib.h>


typedef struct Pair {
    int pos;
    int dis;
}pair;


typedef struct Node {
    int ver;
    int weight;
    struct Node* next;
}node;


int n;
node** arr;
node** back;


int max(int a, int b) {
    return a > b ? a : b;
}


node* createNode(int v2, int weight) {
    node* new = (node*) malloc(sizeof(node));
    new->ver = v2;
    new->weight = weight;
    new->next = NULL;
    return new;
}


void addPath(int v1, int v2, int weight) {
    if (back[v1] == NULL) {
        arr[v1] = createNode(v2, weight);
        back[v1] = arr[v1];
        return;
    }

    back[v1]->next = createNode(v2, weight);
    back[v1] = back[v1]->next;
}


pair dfs(int pos) {
    int* visited = (int*) calloc(n+1, sizeof(int));
    visited[pos] = 1;
    pair* stack = (pair*) malloc(sizeof(pair)*(n+1));
    stack[0].pos = pos;
    stack[0].dis = 0;
    int top = 0;
    
    
    node* path;
    pair furest = {0, 0};
    pair cur;
    while (top != -1) {
        // pop
        cur = stack[top--];
        // printf("pos: %d dis: %d\n", cur.pos, cur.dis);
        if (furest.dis < cur.dis) furest = cur;

        // push
        path = arr[cur.pos];
        while (path) {
            if (visited[path->ver] == 0) {
                visited[path->ver] = 1;
                top += 1;
                stack[top].pos = path->ver;
                stack[top].dis = cur.dis + path->weight;
            }
            path = path->next;
        }
    }


    free(stack);
    free(visited);
    return furest;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (node**) malloc(sizeof(node*)*(n+1));
    // back = (node**) malloc(sizeof(node*)*(n+1));
    // for (int i = 0; i <= n; i++) {
    //     arr[i] = NULL;
    //     back[i] = NULL;
    // }
    // int v1, v2, weight;
    // for (int i = 1; i < n; i++) {
    //     fscanf(file, "%d %d %d", &v1, &v2, &weight);
    //     addPath(v1, v2, weight);
    //     addPath(v2, v1, weight);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (node**) malloc(sizeof(node*)*(n+1));
    back = (node**) malloc(sizeof(node*)*(n+1));
    for (int i = 0; i <= n; i++) {
        arr[i] = NULL;
        back[i] = NULL;
    }
    int v1, v2, weight;
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &v1, &v2, &weight);
        addPath(v1, v2, weight);
        addPath(v2, v1, weight);
    }


    // answer
    pair ans = dfs(1);
    ans = dfs(ans.pos);
    printf("%d\n", ans.dis);


    node* next;
    node* cur;
    // for (int i = 1; i <= n; i++) {
    //     cur = arr[i];
    //     printf("%d: ", i);
    //     while (cur) {
    //         printf("%d ", cur->ver);
    //         cur = cur->next;
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i <= n; i++) {
        cur = arr[i];
        while (cur) {
            next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(arr);
    free(back);
    return 0;
}