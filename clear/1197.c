/*
    title: 최소 스패닝 트리
    tag: graph, MST


    1. Path Compression
    모든 노드가 root를 직접 가리키게 압축

    2. Union by Rank
    높이가 큰(rank가 큰) set에 높이가 작은 set을 붙인다.

    둘 다 적용 시 
    O(Mα(N)) (아커만 함수의 역함수)
*/



#include <stdio.h>
#include <stdlib.h>



typedef struct Edge{
    int u; 
    int v; 
    int w; 
}edge;


int V, E;
edge* arr;
int* parent;
int* rank;


int compare(const void* arg1, const void* arg2) {
    edge* a = (edge*) arg1;
    edge* b = (edge*) arg2;
    return a->w - b->w;
}


void initSet() {
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}


int Find(int ver) {
    if (parent[ver] == ver) return ver;
    return parent[ver] = Find(parent[ver]); // Path Compression
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
    return 0;
}


int kruskal() {
    qsort(arr, E, sizeof(edge), compare);

    
    int acceptedEdge = 0;
    int weightSum = 0;
    edge cur;
    for (int i = 0; i < E; i++) {
        if (acceptedEdge >= V - 1) break;
        cur = arr[i];
        if (Union(cur.u, cur.v)) {
            weightSum += cur.w;
            acceptedEdge += 1;
        }
    }
    return weightSum;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &V, &E);
    // arr = (edge*) malloc(sizeof(edge)*E);
    // for (int i = 0; i < E; i++) {
    //     fscanf(file, "%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &V, &E);
    arr = (edge*) malloc(sizeof(edge)*E);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].w);
    }


    // init
    parent = (int*) malloc(sizeof(int)*(V+1));
    rank = (int*) malloc(sizeof(int)*(V+1));
    initSet();


    // answer
    int ans = kruskal();
    printf("%d\n", ans);


    free(arr);
    free(parent);
    free(rank);
    return 0;
}