/*
    title: 수열과 쿼리 17
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>



#define INF 2000000000
#define min(X, Y) (X) < (Y) ? (X) : (Y)



typedef struct SegmentTree { // 0-based index
    int* tree;
    int size;
    int len;
}SegmentTree;


SegmentTree st;



void initSegmentTree(int len) {
    st.tree = (int*) malloc(sizeof(int)*len*4);
    st.size = len*4;
    st.len = len;
    for (int i = 0; i < st.size; i++) {
        st.tree[i] = INF;
    }
}


void build(int* array, int node, int low, int high) {
    if (low == high) st.tree[node] = array[low];
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        st.tree[node] = min(st.tree[node * 2 + 1], st.tree[node * 2 + 2]); 
    }
}


int query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) return INF; // out of bound
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    int left = query(node * 2 + 1, low, mid, start, end);
    int right = query(node * 2 + 2, mid + 1, high, start, end);
    return min(left, right);
}


void update(int node, int low, int high, int index, int value) {
    if (low == high) st.tree[node] = value;
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        st.tree[node] = min(st.tree[node * 2 + 1], st.tree[node * 2 + 2]);  
    }
}


int range_query(int start, int end) {
    return query(0, 0, st.len-1, start, end);
}


void point_update(int index, int value) {
    update(0, 0, st.len-1, index, value);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int N;
    // fscanf(file, "%d", &N);
    // int* arr = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // initSegmentTree(N);
    // build(arr, 0, 0, N-1);
    // int M;
    // fscanf(file, "%d", &M);
    // int command, v1, v2;
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d %d", &command, &v1, &v2);
    //     if (command == 1) point_update(v1-1, v2);
    //     else printf("%d\n", range_query(v1-1, v2-1)); 
    // }
    // fclose(file);


    // input
    int N;
    scanf("%d", &N);
    int* arr = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    initSegmentTree(N);
    build(arr, 0, 0, N-1);
    int M;
    scanf("%d", &M);
    int command, v1, v2;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &command, &v1, &v2);
        if (command == 1) point_update(v1-1, v2);
        else printf("%d\n", range_query(v1-1, v2-1)); 
    }


    free(arr);
    free(st.tree);
    return 0;
}