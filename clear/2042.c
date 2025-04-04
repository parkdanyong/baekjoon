/*
    title: 구간 합 구하기
    tag: data structure, Segment Tree
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 4000000


typedef long long ll;


typedef struct SegmentTree { // 0-based index
    ll* tree;
    int size;
    int len;
}SegmentTree;


int N, M, K;
ll* arr;
SegmentTree st;


void initSegmentTree(int len) {
    st.tree = (ll*) calloc(len*4, sizeof(ll));
    st.size = len*4;
    st.len = len;
}


void build(ll* array, int node, int low, int high) {
    if (low == high) st.tree[node] = arr[low];
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
    // fscanf(file, "%d %d %d", &N, &M, &K);
    // arr = (ll*) malloc(sizeof(ll)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // initSegmentTree(N);
    // build(arr, 0, 0, N-1);
    // ll ans = 0;
    // ll command, v1, v2;
    // for (int t = 0; t < M+K; t++) {
    //     fscanf(file, "%lld %lld %lld", &command, &v1, &v2);
    //     if (command == 1) point_update((int) v1 - 1, v2);
    //     else if (command == 2) {
    //         ans = range_query((int) v1 - 1, (int) v2 - 1);
    //         printf("%lld\n", ans);
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d %d %d", &N, &M, &K);
    arr = (ll*) malloc(sizeof(ll)*N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }


    // init
    initSegmentTree(N);
    build(arr, 0, 0, N-1);


    // answer
    ll ans = 0;
    ll command, v1, v2;
    for (int t = 0; t < M+K; t++) {
        scanf("%lld %lld %lld", &command, &v1, &v2);
        if (command == 1) point_update((int) v1 - 1, v2);
        else if (command == 2) {
            ans = range_query((int) v1 - 1, (int) v2 - 1);
            printf("%lld\n", ans);
        }
    }


    free(arr);
    free(st.tree);
    return 0;
}