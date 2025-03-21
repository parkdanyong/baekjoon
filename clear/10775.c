/*
    title: 공항
    tag: data structure, greedy, Disjoint Set
*/



#include <stdio.h>
#include <stdlib.h>


int G, P;
int* arr;
int* parent;


int Find(int ver) {
    if (parent[ver] == ver) return ver;
    else return parent[ver] = Find(parent[ver]);
}


int Union(int v1, int v2) {
    if (v2 == 0) return 0;
    parent[v2] = v1;
    return 1;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &G);
    // fscanf(file, "%d", &P);
    // arr = (int*) malloc(sizeof(int)*P);
    // for (int i = 0; i < P; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &G);
    scanf("%d", &P);
    arr = (int*) malloc(sizeof(int)*P);
    for (int i = 0; i < P; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    parent = (int*) malloc(sizeof(int)*(G+1));  
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }


    // answer
    int ans = 0;
    for (int i = 0; i < P; i++) {
        if (Union(Find(arr[i])-1, Find(arr[i])) == 0) break;
        // printf("%d: ", arr[i]);
        // for (int j = 1; j <= G; j++) {
        //     printf("%d ", parent[j]);
        // }
        // printf("\n");
        ans += 1;
    }
    printf("%d\n", ans);


    free(arr);
    free(parent);
    return 0;
}