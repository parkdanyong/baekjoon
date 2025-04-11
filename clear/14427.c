/*
    title: 수열과 쿼리 15 
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 2000000000
#define min(X, Y) (X) < (Y) ? (X) : (Y)


typedef struct Node {
    int val;
    int index;
}Node;



typedef struct SegmentTree { // 0-based index
    Node* tree;
    int size;
    int len;
}SegmentTree;




SegmentTree st;




void initSegmentTree(int len) {
    st.tree = (Node*) calloc(len*4, sizeof(Node));
    st.size = len*4;
    st.len = len;
}


void build(int* array, int node, int low, int high) {
    if (low == high) {
        st.tree[node].val = array[low];
        st.tree[node].index = low;
    }
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        if (st.tree[node * 2 + 1].val < st.tree[node * 2 + 2].val) st.tree[node] = st.tree[node * 2 + 1];
        else if (st.tree[node * 2 + 1].val > st.tree[node * 2 + 2].val) st.tree[node] = st.tree[node * 2 + 2];
        else {
            if (st.tree[node * 2 + 1].index < st.tree[node * 2 + 2].index) st.tree[node] = st.tree[node * 2 + 1];
            else st.tree[node] = st.tree[node * 2 + 2];
        }
    }
}


Node query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) { // out of bound
        Node tmp = {INF, 0};
        return tmp;
    }
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    Node left = query(node * 2 + 1, low, mid, start, end);
    Node right = query(node * 2 + 2, mid + 1, high, start, end);
    if (left.val < right.val) return left;
    else if (left.val > right.val) return right;
    else {
        if (left.index < right.index) return left;
        else return right;
    }
}


void update(int node, int low, int high, int index, int value) {
    if (low == high) st.tree[node].val = value;
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        if (st.tree[node * 2 + 1].val < st.tree[node * 2 + 2].val) st.tree[node] = st.tree[node * 2 + 1];
        else if (st.tree[node * 2 + 1].val > st.tree[node * 2 + 2].val) st.tree[node] = st.tree[node * 2 + 2];
        else {
            if (st.tree[node * 2 + 1].index < st.tree[node * 2 + 2].index) st.tree[node] = st.tree[node * 2 + 1];
            else st.tree[node] = st.tree[node * 2 + 2];
        } 
    }
}


Node range_query(int start, int end) {
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
    // int command, v1, v2;
    // int M;
    // fscanf(file, "%d", &M);
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d", &command);
    //     if (command == 1) {
    //         fscanf(file, "%d %d", &v1, &v2);
    //         point_update(v1-1, v2);
    //     }
    //     else printf("%d\n", range_query(0, N-1).index + 1);
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
    int command, v1, v2;
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &command);
        if (command == 1) {
            scanf("%d %d", &v1, &v2);
            point_update(v1-1, v2);
        }
        else printf("%d\n", range_query(0, N-1).index + 1);
    }


    free(arr);
    free(st.tree);
    return 0;
}