/*
    title: 커피숍2
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


typedef struct SegmentTree { // 0-based index
    ll* tree;
    int size;
    int len;
}SegmentTree;



SegmentTree st;



void initSegmentTree(int len) {
    st.tree = (ll*) calloc(len*4, sizeof(ll));
    st.size = len*4;
    st.len = len;
}


void build(ll* array, int node, int low, int high) {
    if (low == high) st.tree[node] = array[low];
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        st.tree[node] = st.tree[node * 2 + 1] + st.tree[node * 2 + 2]; 
    }
}


ll query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) return 0; // out of bound
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    ll left_sum = query(node * 2 + 1, low, mid, start, end);
    ll right_sum = query(node * 2 + 2, mid + 1, high, start, end);
    return left_sum + right_sum;
}


void update(int node, int low, int high, int index, ll value) {
    if (low == high) st.tree[node] = value;
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        st.tree[node] = st.tree[node * 2 + 1] + st.tree[node * 2 + 2];  
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
    // int N, Q;
    // fscanf(file, "%d %d", &N, &Q);
    // ll* arr = (ll*) malloc(sizeof(ll)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // initSegmentTree(N);
    // build(arr, 0, 0, N-1);
    // int x, y, a, b;
    // for (int i = 0; i < Q; i++) {
    //     fscanf(file, "%d %d %d %d", &x, &y, &a, &b);
    //     if (x <= y) printf("%lld\n", range_query(x-1, y-1));
    //     else printf("%lld\n", range_query(y-1, x-1));
    //     point_update(a-1, (ll) b);
    // }
    // fclose(file);


    // input
    int N, Q;
    scanf("%d %d", &N, &Q);
    ll* arr = (ll*) malloc(sizeof(ll)*N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }
    initSegmentTree(N);
    build(arr, 0, 0, N-1);
    int x, y, a, b;
    for (int i = 0; i < Q; i++) {
        scanf("%d %d %d %d", &x, &y, &a, &b);
        if (x <= y) printf("%lld\n", range_query(x-1, y-1));
        else printf("%lld\n", range_query(y-1, x-1));
        point_update(a-1, (ll) b);
    }


    free(arr);
    free(st.tree);
    return 0;
}