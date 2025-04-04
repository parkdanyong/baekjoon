/*
    title: 수열과 쿼리 16
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>



#define INF 2000000000



typedef struct Pair {
    int v1;
    int v2;
}Pair;


typedef struct SegmentTree { // 0-based index
    Pair* tree;
    int size;
    int len;
}SegmentTree;



SegmentTree st;



void initSegmentTree(int len) {
    st.tree = (Pair*) malloc(sizeof(Pair)*len*4);
    st.size = len*4;
    st.len = len;
    for (int i = 0; i < st.size; i++) {
        st.tree[i].v1 = 0;
        st.tree[i].v2 = INF;
    }
}


void build(int* array, int node, int low, int high) {
    if (low == high) {
        st.tree[node].v1 = low;
        st.tree[node].v2 = array[low];
    }
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        if (st.tree[node * 2 + 1].v2 <= st.tree[node * 2 + 2].v2) {
            st.tree[node].v1 = st.tree[node * 2 + 1].v1;
            st.tree[node].v2 = st.tree[node * 2 + 1].v2;
        }
        else {
            st.tree[node].v1 = st.tree[node * 2 + 2].v1;
            st.tree[node].v2 = st.tree[node * 2 + 2].v2;
        }
    }
}


Pair query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) { // out of bound
        Pair tmp = {0, INF};
        return tmp;
    } 
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    Pair left = query(node * 2 + 1, low, mid, start, end);
    Pair right = query(node * 2 + 2, mid + 1, high, start, end);
    if (left.v2 <= right.v2) return left;
    else return right;
}


void update(int node, int low, int high, int index, int value) {
    if (low == high) {
        st.tree[node].v1 = index;
        st.tree[node].v2 = value;
    }
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        if (st.tree[node * 2 + 1].v2 <= st.tree[node * 2 + 2].v2) {
            st.tree[node].v1 = st.tree[node * 2 + 1].v1;
            st.tree[node].v2 = st.tree[node * 2 + 1].v2;
        }
        else {
            st.tree[node].v1 = st.tree[node * 2 + 2].v1;
            st.tree[node].v2 = st.tree[node * 2 + 2].v2;
        }
    }
}


Pair range_query(int start, int end) {
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
    //     else printf("%d\n", range_query(v1-1, v2-1).v1 + 1);
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
        else printf("%d\n", range_query(v1-1, v2-1).v1 + 1);
    }


    free(arr);
    free(st.tree);
    return 0;
}