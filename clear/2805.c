/*
    title: 나무 자르기
    tag: parameter search


    isSatisfy -> O(n)
    upperBound -> O(logn) 
    combined function -> O(nlogn)
*/
    



#include <stdio.h>
#include <stdlib.h>



typedef long long ll;



int compare(const void* a, const void* b) {
    return *(int*)b - *(int*)a; // descending order
}


int isSatisfy(int* tree, int len, int m, int h) {
    // O(n)

    ll sum = 0;
    int tmp;
    for (int i = 0; i < len; i++) {
        tmp = tree[i] - h;
        if (tmp <= 0) break;
        sum += tmp;
        if (sum >= m) return 1;
    }

    return 0;
}


int upperBound(int* tree, int len, int m) { 
    // O(logn) 

    int low = -1;
    int high = tree[0] + 1;
    int mid = 0;
    while (low + 1 < high) {
        mid = low + (int) (high - low) / 2;
        if (isSatisfy(tree, len, m, mid) == 1) low = mid; 
        else high = mid;
    }

    return high;
}



int main() {
    FILE* file = fopen("inputFile.txt", "r");
    int n, m;
    fscanf(file, "%d %d", &n, &m);
    int* tree = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &tree[i]);
    }
    fclose(file);


    // input
    // int n, m;
    // scanf("%d %d", &n, &m);
    // int* tree = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &tree[i]);
    // }


    // init
    qsort(tree, n, sizeof(int), compare);


    // answer
    printf("%d\n", upperBound(tree, n, m) - 1);


    free(tree);
    return 0;
}


