/*
    title: 구간 곱 구하기
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 4000000
#define MOD 1000000007


typedef long long ll;


typedef struct SegmentTree { // 0-based index
    ll* tree;
    int size;
    int len;
}SegmentTree;



SegmentTree st;



void initSegmentTree(int len) {
    st.tree = (ll*) malloc(sizeof(ll)*len*4);
    st.size = len*4;
    st.len = len;
    for (int i = 0; i < st.size; i++) {
        st.tree[i] = 1;
    }
}


void build(ll* array, int node, int low, int high) {
    if (low == high) st.tree[node] = array[low];
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        st.tree[node] = (st.tree[node * 2 + 1] * st.tree[node * 2 + 2]) % MOD; 
    }
}


ll query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) return 1; // out of bound
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    ll left = query(node * 2 + 1, low, mid, start, end);
    ll right = query(node * 2 + 2, mid + 1, high, start, end);
    return (left * right) % MOD;
}


void update(int node, int low, int high, int index, ll value) {
    if (low == high) st.tree[node] = value;
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        st.tree[node] = (st.tree[node * 2 + 1] * st.tree[node * 2 + 2]) % MOD;  
    }
}


ll range_query(int start, int end) {
    return query(0, 0, st.len-1, start, end);
}


void point_update(int index, ll value) {
    update(0, 0, st.len-1, index, value);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int N, M, K;
    // fscanf(file, "%d %d %d", &N, &M, &K);
    // ll* arr = (ll*) malloc(sizeof(ll)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // initSegmentTree(N);
    // build(arr, 0, 0, N-1);
    // int T = M + K;
    // int command, v1, v2;
    // for (int i = 0; i < T; i++) {
    //     fscanf(file, "%d %d %d", &command, &v1, &v2);
    //     if (command == 1) point_update(v1-1, (ll) v2);
    //     else printf("%lld\n", range_query(v1-1, v2-1));
    // }
    // fclose(file);


    // input
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    ll* arr = (ll*) malloc(sizeof(ll)*N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    initSegmentTree(N);
    build(arr, 0, 0, N-1);
    int T = M + K;
    int command, v1, v2;
    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &command, &v1, &v2);
        if (command == 1) point_update(v1-1, (ll) v2);
        else printf("%lld\n", range_query(v1-1, v2-1));
    }


    free(arr);
    free(st.tree);
    return 0;
}