/*
    Segment Tree

    세그먼트 트리는 구간 쿼리(Range Query) 및 구간 업데이트(Range Update) 를 빠르게 수행하기 위한 트리 자료구조

    Build 시간 복잡도: O(NlohN)

    1. 트리 기반 구조
        노드가 배열의 특정 구간 정보를 저장함.
        루트 노드는 전체 배열의 정보를 저장함.

    2. 빠른 쿼리 처리
        구간 합(sum), 최댓값(max), 최솟값(min) 등의 질의를 O(log N) 에 해결 가능.
        단순한 O(N) 브루트포스 접근보다 효율적.
    
    3. 빠른 업데이트
        특정 원소 값을 변경하면 관련 노드만 O(log N) 에 업데이트됨.
    
    4. 구현 방식
        보통 배열을 기반으로 한 완전 이진 트리로 표현됨.
        일반적인 크기는 4N 정도의 배열을 사용.
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
    int N = 10;
    int* array = calloc(N, sizeof(int));
    

    initSegmentTree(N);
    build(array, 0, 0, N-1);
    ll v1, v2;
    // if tree is 1-based index, sub 1.
    ll ans = range_query((int) v1-1, (int) v2-1);
    point_update((int) v1-1, v2);


    free(array);
    free(st.tree);
    return 0;
}