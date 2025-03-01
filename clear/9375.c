/*
    title: 패션왕 신해빈
    tag: math, combinatorics, HashMap, HashSet
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char type[30];
    int count;
}node;


int compare(const void* arg1, const void* arg2) {
    node* a = (node*) arg1;
    node* b = (node*) arg2;

    return strcmp(a->type, b->type);
}


int removeDuplicates(node* arr, int n) {
    if (n == 0) return 0;
    int len = 0;
    arr[len].count = 1;

    for (int i = 1; i < n; i++) {
        if (strcmp(arr[len].type, arr[i].type) != 0) {
            len++;
            strcpy(arr[len].type, arr[i].type);
            arr[len].count = 1;
        }
        else arr[len].count += 1;
    }

    return len + 1;
}


int main() {
    FILE* file = fopen("inputFile.txt", "r");
    int t;
    fscanf(file, "%d", &t);
    // scanf("%d", &t);
    int n;
    
    
    
    // init
    node* arr = malloc(sizeof(node)*31);


    // answer
    int ans = 0;
    for (int i = 0; i < t; i++) {
        fscanf(file, "%d", &n);
        // scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            fscanf(file, "%*s %s", arr[j].type);
            // scanf("%*s %s", arr[j].type);
            arr[i].count = 0;
        }
        for (int j = 0; j < n; j++) {
            printf("%s\n", arr[j].type);
        }
        printf("\n");


        qsort(arr, n, sizeof(node), compare);
        for (int j = 0; j < n; j++) {
            printf("%s\n", arr[j].type);
        }
        printf("\n");
        n = removeDuplicates(arr, n);
        for (int j = 0; j < n; j++) {
            printf("%s %d\n", arr[j].type, arr[j].count);
        }

        ans = 1;
        for (int j = 0; j < n; j++) {
            ans *= (arr[j].count + 1);
        }
        printf("%d\n", ans - 1);
    }


    fclose(file);
    free(arr);
    return 0;
}