/*
    title: 대칭 차집합
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE  200000


typedef struct Node {
    int value;
    struct Node* next;
} Node;


typedef struct HashSet {
    Node* buckets[TABLE_SIZE];
    int stack[TABLE_SIZE];
    int top;
} HashSet;



int a, b;
HashSet* A;
HashSet* B;



int hash(int value) {
    return value % TABLE_SIZE;
}


HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    memset(set->buckets, 0, sizeof(set->buckets));
    set->top = -1;
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
    set->stack[++set->top] = value;
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




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &a, &b);
    // A = createHashSet();
    // B = createHashSet();
    // int v;
    // for (int i = 0; i < a; i++) {
    //     fscanf(file, "%d", &v);
    //     add(A, v);
    // }   
    // for (int i = 0; i < b; i++) {
    //     fscanf(file, "%d", &v);
    //     add(B, v);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &a, &b);
    A = createHashSet();
    B = createHashSet();
    int v;
    for (int i = 0; i < a; i++) {
        scanf("%d", &v);
        add(A, v);
    }   
    for (int i = 0; i < b; i++) {
        scanf("%d", &v);
        add(B, v);
    }


    // answer
    int ans = 0;
    // A - B
    int top = B->top;
    for (int i = 0; i <= top; i++) {
        if (contains(A, B->stack[i]) == 0) ans += 1;
    }
    top = A->top;
    for (int i = 0; i <= top; i++) {
        if (contains(B, A->stack[i]) == 0) ans += 1;
    }
    printf("%d\n", ans);



    freeHashSet(A);
    freeHashSet(B);
    return 0;
}