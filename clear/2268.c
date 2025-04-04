/*
    title: 수들의 합 7
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
    // int N, M;
    // fscanf(file, "%d %d", &N, &M);
    // initSegmentTree(N);
    // int command, v1, v2;
    // for (int i = 0; i < M; i++) {
    //     fscanf(file, "%d %d %d", &command, &v1, &v2);
    //     if (command) point_update(v1-1, (ll) v2);
    //     else {
        //     if (v1 <= v2) printf("%lld\n", range_query(v1-1, v2-1));
        //     else printf("%lld\n", range_query(v2-1, v1-1));
        // }
    // }
    // fclose(file);


    // input
    int N, M;
    scanf("%d %d", &N, &M);
    initSegmentTree(N);
    int command, v1, v2;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &command, &v1, &v2);
        if (command) point_update(v1-1, (ll) v2);
        else {
            if (v1 <= v2) printf("%lld\n", range_query(v1-1, v2-1));
            else printf("%lld\n", range_query(v2-1, v1-1));
        }
    }


    free(st.tree);
    return 0;
}