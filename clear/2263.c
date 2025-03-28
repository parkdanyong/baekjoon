/*
    title: 트리의 순회
    tag: divide and conquer, reculsion


    binary tree
*/



#include <stdio.h>
#include <stdlib.h>


int N;
int* inorder;
int* postorder;


void getPreorder(int root, int leaf, int start, int end) {
    if (end < start) return;
    // printf("%d %d %d %d\n", root, leaf, start, end);
    printf("%d ", postorder[root]);

    int pos = -1;
    for (int i = 0; i < N; i++) {
        if (inorder[i] == postorder[root]) pos = i;
    }

    int L_root = leaf + (pos - 1 - start);
    int R_root = L_root + (end - (pos + 1)) + 1;
    if (pos == -1) return;
    if (start < pos) getPreorder(L_root, leaf, start, pos-1);
    if (pos < end) getPreorder(R_root, L_root+1, pos+1, end);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // inorder = (int*) malloc(sizeof(int)*N);
    // postorder = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &inorder[i]);
    // }
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &postorder[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    inorder = (int*) malloc(sizeof(int)*N);
    postorder = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &inorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &postorder[i]);
    }


    // answer
    getPreorder(N-1, 0, 0, N-1);
    

    free(inorder);
    free(postorder);
    return 0;
}