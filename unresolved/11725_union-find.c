/*
    title: 트리의 부모 찾기
    tag: data structure, union-find
    
*/


#include <stdio.h>
#include <stdlib.h>


int* createSet(int size) {
    int* pset = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        pset[i] = -1;
    }

    return pset;
}


int find(int* pset, int nodeNum) {
    int n = nodeNum;

    while (pset[n] >= 0) {
        n = pset[n];
    }

    return n;
}


void setUnion(int* pset, int s1, int s2) {
    int s1_p = find(pset, s1);  
    int s2_p = find(pset, s2);
    printf("%d %d\n", s1_p, s2_p);
    if (s1_p != s2_p) {
        if (s1 == s1_p && s2 == s2_p) {
            pset[s1] = s2;
            pset[s2] = s1;
        }
        else if (s1 == 0 || s1_p == 0) pset[s2] = s1;
        else if (s2 == 0 || s2_p == 0) pset[s1] = s2;
        else if (s1 != s1_p && s2 == s2_p) pset[s2] = s1;
        else if (s1 == s1_p && s2 != s2_p) pset[s1] = s2;
    }
}


void printSet(int* pset, int size) {
    for (int i = 1; i < size; i++) {
        printf("%d\n", pset[i]+1);
    }
}



int main() {
    FILE* file = fopen("inputFile.txt", "r");


    // init parent set
    int size = 0;
    // scanf("%d", &size);
    fscanf(file, "%d", &size);
    int* pset = createSet(size);

    
    int s1, s2;
    for (int i = 0; i < size-1; i++) {
        fscanf(file, "%d %d", &s1, &s2);
        // scanf("%d %d", &s1, &s2);
        s1 -= 1;
        s2 -= 1;
        setUnion(pset, s1, s2);
    }

    printSet(pset, size);

    fclose(file);
    free(pset);
    return 0;
}


