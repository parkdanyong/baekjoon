/*
    title: 이진 검색 트리
    tag: tree, recursion


    preorder: tree structure
    inorder: ascending order
    postorder: 

*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 10000


int n;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


void getPostOrder(int root, int end) {
    if (end < 0) return;

    int rightChild = -1;
    for (int i = root+1; i <= end; i++) {
        if (arr[root] < arr[i]) {
            rightChild = i;
            break;
        }
    }

    if (root+1 <= end && rightChild != root+1) {
        if (rightChild == -1) getPostOrder(root+1, end);
        else getPostOrder(root+1, rightChild-1);
    }
    if (rightChild != -1) getPostOrder(rightChild, end);
    printf("%d\n", arr[root]);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // n = 0;
    // arr = (int*) calloc(MAX_SIZE, sizeof(int));
    // int tmp;
    // while (1) {
    //     if (fscanf(file, "%d", &tmp) == EOF) break;
    //     arr[n++] = tmp;
    // }
    // fclose(file);


    // input
    n = 0;
    arr = (int*) calloc(MAX_SIZE, sizeof(int));
    int tmp;
    while (1) {
        if (scanf("%d", &tmp) == EOF) break;
        arr[n++] = tmp;
    }


    // answer
    getPostOrder(0, n-1);


    free(arr);
    arr = NULL;
    return 0;
}