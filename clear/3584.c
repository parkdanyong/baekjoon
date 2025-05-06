/*
    title: 가장 가까운 공통 조상
    tag: 

    LCA (Lowest Common Ancestor)
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ARRAY_SIZE 10100
#define TABLE_SIZE 20000


typedef struct Node {
    int value;
    struct Node* next;
} Node;


typedef struct HashSet {
    Node* buckets[TABLE_SIZE];
} HashSet;



int T, N;
int* arr;



int hash(int value) {
    return value % TABLE_SIZE;
}


HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    memset(set->buckets, 0, sizeof(set->buckets));
    return set;
}


void add(HashSet* set, int value) {
    int index = hash(value);
    Node* cur = set->buckets[index];
    while (cur) {
        if (cur->value == value) return; 
        cur = cur->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
}


int contains(HashSet* set, int value) {
    int index = hash(value);
    Node* cur = set->buckets[index];
    while (cur) {
        if (cur->value == value) return 1;
        cur = cur->next;
    }
    return 0;
}


void freeHashSet(HashSet* set) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* cur = set->buckets[i];
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(set);
}


int findParent(int v1, int v2) {
    HashSet* set = createHashSet();

    int cur = v1;
    while (1) {
        if (cur == 0) break;
        add(set, cur);
        cur = arr[cur];
    }

    cur = v2;
    while (1) {
        if (cur == 0) break;
        if (contains(set, cur)) {
            freeHashSet(set);
            return cur;
        }
        cur = arr[cur];
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &T);
    // arr = (int*) malloc(sizeof(int)*MAX_ARRAY_SIZE);
    // int ans, v1, v2;
    // for (int t = 0; t < T; t++) {
    //     fscanf(file, "%d", &N);
    //     memset(arr, 0, MAX_ARRAY_SIZE);
    //     for (int i = 1; i < N; i++) {
    //         fscanf(file, "%d %d", &v1, &v2);
    //         arr[v2] = v1;
    //     }
    //     fscanf(file, "%d %d", &v1, &v2);
    //     ans = findParent(v1, v2);
    //     printf("%d\n", ans);
    // }
    // fclose(file);


    // input
    scanf("%d", &T);
    arr = (int*) malloc(sizeof(int)*MAX_ARRAY_SIZE);
    int ans, v1, v2;
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        memset(arr, 0, MAX_ARRAY_SIZE);
        for (int i = 1; i < N; i++) {
            scanf("%d %d", &v1, &v2);
            arr[v2] = v1;
        }
        scanf("%d %d", &v1, &v2);
        ans = findParent(v1, v2);
        printf("%d\n", ans);
    }



    free(arr);
    return 0;
}