/*
    title: 사이클 게임
    tag: graph, Union-Find
*/



#include <stdio.h>
#include <stdlib.h>



int n, m;
int* parent;
int* rank;


void initSet() {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}


int Find(int ver) {
    if (parent[ver] == ver) return ver;
    else return parent[ver] = Find(parent[ver]);
}


int Union(int v1, int v2) {
    int v1_p = Find(v1);
    int v2_p = Find(v2);

    if (v1_p != v2_p) {
        if (rank[v1_p] > rank[v2_p]) parent[v2_p] = v1_p;
        else if (rank[v1_p] < rank[v2_p]) parent[v1_p] = v2_p;
        else {
            parent[v2_p] = v1_p;
            rank[v1_p] += 1;
        }
        return 1;
    }
    else return 0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // parent = (int*) malloc(sizeof(int)*n);
    // rank = (int*) malloc(sizeof(int)*n);
    // initSet();
    // int i, v1, v2, flag = 0;
    // for (i = 1; i <= m; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     if (Union(v1, v2) == 0) {
    //         flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 0) i = 0;
    // printf("%d\n", i);
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);


    // init
    parent = (int*) malloc(sizeof(int)*n);
    rank = (int*) malloc(sizeof(int)*n);
    initSet();


    // answer
    int i, v1, v2, flag = 0;
    for (i = 1; i <= m; i++) {
        scanf("%d %d", &v1, &v2);
        if (Union(v1, v2) == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) i = 0;
    printf("%d\n", i);


    free(parent);
    free(rank);
    return 0;
} 