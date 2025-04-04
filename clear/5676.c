/*
    title: 음주 코딩
    tag: segment tree
*/



#include <stdio.h>
#include <stdlib.h>


#define ARRAY_MAX_SIZE 100000


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
        st.tree[i] = 1;
    }
}


void build(int* array, int node, int low, int high) {
    if (low == high) st.tree[node] = array[low];
    else {
        int mid = low + (high - low) / 2;
        build(array, node * 2 + 1, low, mid);
        build(array, node * 2 + 2, mid + 1, high);
        st.tree[node] = st.tree[node * 2 + 1] * st.tree[node * 2 + 2]; 
    }
}


int query(int node, int low, int high, int start, int end) {
    if (end < low || high < start) return 1; // out of bound
    if (start <= low && high <= end) return st.tree[node]; // contain
    int mid = low + (high - low) / 2;
    int left = query(node * 2 + 1, low, mid, start, end);
    int right = query(node * 2 + 2, mid + 1, high, start, end);
    return left * right;
}


void update(int node, int low, int high, int index, int value) {
    if (low == high) st.tree[node] = value;
    else {
        int mid = low + (high - low) / 2;
        if (index <= mid) update(node * 2 + 1, low, mid, index, value);
        else update(node * 2 + 2, mid + 1, high, index, value);
        st.tree[node] = st.tree[node * 2 + 1] * st.tree[node * 2 + 2];  
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
    // int N, K;
    // int* arr = (int*) malloc(sizeof(int)*ARRAY_MAX_SIZE);
    // char command;
    // int v1, v2, state, ans;
    // while (1) {
    //     state = fscanf(file, "%d %d", &N, &K);
    //     if (state == EOF) break;


    //     for (int i = 0; i < N; i++) {
    //         fscanf(file, "%d", &ans);
    //         if (0 < ans) arr[i] = 1;
    //         else if (ans < 0) arr[i] = -1;
    //         else arr[i] = 0;
    //     }
    //     initSegmentTree(N);
    //     build(arr, 0, 0, N-1);


    //     for (int i = 0; i < K; i++) {
    //         fscanf(file, " %c %d %d", &command, &v1, &v2);
    //         if (command == 'P') {
    //             ans = range_query(v1-1, v2-1);
    //             if (0 < ans) printf("+");
    //             else if (ans < 0) printf("-");
    //             else printf("0");
    //         }
    //         else if (command == 'C') {
    //             if (0 < v2) point_update(v1-1, 1);
    //             else if (v2 < 0) point_update(v1-1, -1);
    //             else point_update(v1-1, 0);
    //         }
    //     }
    //     printf("\n");
    //     free(st.tree);
    // }
    // fclose(file);


    // input
    int N, K;
    int* arr = (int*) malloc(sizeof(int)*ARRAY_MAX_SIZE);
    char command;
    int v1, v2, state, ans;
    while (1) {
        state = scanf("%d %d", &N, &K);
        if (state == EOF) break;

        // init
        for (int i = 0; i < N; i++) {
            scanf("%d", &ans);
            if (0 < ans) arr[i] = 1;
            else if (ans < 0) arr[i] = -1;
            else arr[i] = 0;
        }
        initSegmentTree(N);
        build(arr, 0, 0, N-1);

        // answer
        for (int i = 0; i < K; i++) {
            scanf(" %c %d %d", &command, &v1, &v2);
            if (command == 'P') {
                ans = range_query(v1-1, v2-1);
                if (0 < ans) printf("+");
                else if (ans < 0) printf("-");
                else printf("0");
            }
            else if (command == 'C') {
                if (0 < v2) point_update(v1-1, 1);
                else if (v2 < 0) point_update(v1-1, -1);
                else point_update(v1-1, 0);
            }
        }
        printf("\n");
        free(st.tree);
    }


    free(arr);
    return 0;
}