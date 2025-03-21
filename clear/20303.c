/*
    title: 할로윈의 양아치
    tag: graph, Union-Find, 
*/



#include <stdio.h>
#include <stdlib.h>


#define max(X, Y) (X) > (Y) ? (X) : (Y)



typedef struct Item {
    int W;
    int V;
}Item;


int N, M, K;
int* parent;
int* rank;
Item* candy;



void initSet() {
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
        rank[i] = 1;
        candy[i].V = 0;
        candy[i].W = 1;
    }
}


int Find(int ver) {
    if (parent[ver] == ver) return ver;
    else return parent[ver] = Find(parent[ver]);
}


void Union(int v1, int v2) {
    int v1_p = Find(v1);
    int v2_p = Find(v2);
    if (v1_p == v2_p) return;
    else if (rank[v1_p] > rank[v2_p]) {
        parent[v2_p] = v1_p;
        candy[v1_p].V += candy[v2_p].V;
        candy[v1_p].W += candy[v2_p].W;
    }
    else if (rank[v1_p] < rank[v2_p]) {
        parent[v1_p] = v2_p;
        candy[v2_p].V += candy[v1_p].V;
        candy[v2_p].W += candy[v1_p].W;
    }
    else {
        parent[v2_p] = v1_p;
        rank[v1_p] += 1;
        candy[v1_p].V += candy[v2_p].V;
        candy[v1_p].W += candy[v2_p].W;
    }
}


int compare(const void* arg1, const void* arg2) {
    Item* a = (Item*) arg1;
    Item* b = (Item*) arg2;
    int cmp = a->W - b->W;
    if (cmp) return cmp;
    return b->V - a->V;
}


int knapsack(Item* items, int n, int w) {
    int* bag = (int*) calloc((n+1)*(w+1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j < items[i].W) bag[i * (w+1) + j] = bag[(i-1) * (w+1) + j];
            else bag[i * (w+1) + j] = max(bag[(i-1) * (w+1) + j], bag[(i-1) * (w+1) + (j - items[i].W)] + items[i].V);
        }
    }

    int result = bag[(w+1)*n + w];
    free(bag);
    return result;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &N, &M, &K);
    // candy = (Item*) malloc(sizeof(Item)*(N+1));
    // parent = (int*) malloc(sizeof(int)*(N+1));
    // rank = (int*) malloc(sizeof(int)*(N+1));
    // int v1, v2;
    // initSet();
    // for (int i = 1; i <= N; i++) {
    //     fscanf(file, "%d", &candy[i].V);
    // }
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     Union(v1, v2);
    // }
    // fclose(file);


    // input
    scanf("%d %d %d", &N, &M, &K);
    candy = (Item*) malloc(sizeof(Item)*(N+1));
    parent = (int*) malloc(sizeof(int)*(N+1));
    rank = (int*) malloc(sizeof(int)*(N+1));
    int v1, v2;
    initSet();
    for (int i = 1; i <= N; i++) {
        scanf("%d", &candy[i].V);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &v1, &v2);
        Union(v1, v2);
    }
    

    // answer
    Item* stack = malloc(sizeof(Item)*(N+2));
    stack[0].V = 0;
    stack[0].W = 0;
    int top = 0;
    for (int i = 1; i <= N; i++) {
        if (Find(i) == i) stack[++top] = candy[i];
    }
    qsort(stack, top+1, sizeof(Item), compare);
    int ans = knapsack(stack, top+1, K-1);
    printf("%d\n", ans); 


    free(candy);
    free(parent);
    free(rank);
    free(stack);
    return 0;
}