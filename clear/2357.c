/*
    title: 최솟값과 최댓값
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>


#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define max(X, Y) (X) > (Y) ? (X) : (Y)
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
    st.tree = (Pair*) calloc(len*4, sizeof(Pair));
    st.size = len*4;
    st.len = len;
    for (int i = 0; i < st.size; i++) {
        st.tree[i].v1 = INF; // min
        st.tree[i].v2 = 0; // max
    }
}


void build(int* array, int node, int low, int high) {
    if (low == high) {
        st.tree[node].v1 = array[low];
        st.tree[node].v2 = array[low];
    }
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        st.tree[node].v1 = min(st.tree[node * 2 + 1].v1, st.tree[node * 2 + 2].v1); 
        st.tree[node].v2 = max(st.tree[node * 2 + 1].v2, st.tree[node * 2 + 2].v2); 
    }
}



Pair query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) { // out of bound
        Pair tmp = {INF, 0};
        return tmp;
    }
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    Pair left = query(node * 2 + 1, low, mid, start, end);
    Pair right = query(node * 2 + 2, mid + 1, high, start, end);
    Pair rv = {min(left.v1, right.v1), max(left.v2, right.v2)};
    return rv;
}


Pair range_query(int start, int end) {
    return query(0, 0, st.len-1, start, end);
}




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int N, M;
    // fscanf(file, "%d %d", &N, &M);
    // int* arr = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // initSegmentTree(N);
    // build(arr, 0, 0, N-1);
    // int v1, v2;
    // Pair ans;
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     ans = range_query(v1-1, v2-1); // 0-based index
    //     printf("%d %d\n", ans.v1, ans.v2);
    // }
    // fclose(file);


    // input
    int N, M;
    scanf("%d %d", &N, &M);
    int* arr = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    initSegmentTree(N);
    build(arr, 0, 0, N-1);
    int v1, v2;
    Pair ans;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &v1, &v2);
        ans = range_query(v1-1, v2-1); // 0-based index
        printf("%d %d\n", ans.v1, ans.v2);
    }


    free(arr);
    free(st.tree);
    return 0;
}