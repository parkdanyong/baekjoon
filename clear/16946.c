/*
    title: 벽 부수고 이동하기 4
    tag: graph, Union-Find, BFS, DFS, Flood-Fill
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


int rows, cols, size;
int* arr;
int* parent;
int* rank;
ll* houseSize;


void initSet() {
    for (int i = 0; i < size; i++) {
        parent[i] = i;
        rank[i] = 1;
        houseSize[i] = 1;
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
        houseSize[v1_p] += houseSize[v2_p];
    }
    else if (rank[v1_p] < rank[v2_p]) {
        parent[v1_p] = v2_p;
        houseSize[v2_p] += houseSize[v1_p];
    }
    else {
        parent[v2_p] = v1_p;
        rank[v1_p] += 1;
        houseSize[v1_p] += houseSize[v2_p];
    }
}


void initHouseSize() {
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            if (i + 1 < size && i % cols + 1 < cols) {
                if (arr[i + 1] == 0) Union(i, i + 1);
            }
            if (0 <= i - 1 && 0 <= i % cols - 1) {
                if (arr[i - 1] == 0) Union(i, i - 1);
            }
            if (i + cols < size) {
                if (arr[i + cols] == 0) Union(i, i + cols);
            }
            if (0 <= i - cols) {
                if (arr[i - cols] == 0) Union(i, i - cols);
            }
        }
    }
}


void contain(int stack[], int* top, int cmp, ll* ans) {
    int flag = 1;
    for (int i = 0; i <= *top; i++) {
        if (stack[i] == cmp) flag = 0;
    }
    if (flag) {
        *top += 1;
        stack[*top] = cmp;
        *ans += houseSize[cmp];
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     arr[i] = fgetc(file);
    //     if (arr[i] == '\n') i -= 1;
    //     else arr[i] -= '0';
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        arr[i] = fgetc(stdin);
        if (arr[i] == '\n') i -= 1;
        else arr[i] -= '0';
    }


    // init
    parent = (int*) malloc(sizeof(int)*size);
    rank = (int*) malloc(sizeof(int)*size);
    houseSize = (ll*) malloc(sizeof(ll)*size);
    initSet();
    initHouseSize();


    // answer
    int stack[4];
    int top = -1;
    ll ans = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) {
            top = -1;
            ans = 1;
            if (i + 1 < size && i % cols + 1 < cols) {
                if (arr[i + 1] == 0) contain(stack, &top, Find(i + 1), &ans);
            }
            if (0 <= i - 1 && 0 <= i % cols - 1) {
                if (arr[i - 1] == 0) contain(stack, &top, Find(i - 1), &ans);
            }
            if (i + cols < size) {
                if (arr[i + cols] == 0) contain(stack, &top, Find(i + cols), &ans);
            }
            if (0 <= i - cols) {
                if (arr[i - cols] == 0) contain(stack, &top, Find(i - cols), &ans);
            }
            houseSize[i] = ans;
        }
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) printf("0");
        else printf("%d", houseSize[i]%10);
        if ((i+1)%cols == 0) printf("\n");
    }


    free(arr);
    free(parent);
    free(rank);
    free(houseSize);
    return 0;
}