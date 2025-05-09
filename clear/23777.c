/*
    title: Knitpicking
    tag: 비둘기집 원리, hash set

    N개의 종류가 있을 때, N+1 개를 뽑으면 반드시 하나는 겹친다.
    N개의 집에 N+1마리의 비둘기를 넣을 때, 반드시 하나의 집에는 2마리의 비둘기가 있다.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define max(X, Y) (X) > (Y) ? (X) : (Y)
#define TABLE_SIZE 1000
#define MAX_STR_LEN 30



typedef struct Node {
    char key[50];
    int value[3];
    struct Node* next;
} Node;


typedef struct HashMap {
    Node* buckets[TABLE_SIZE];
    char stack[TABLE_SIZE][MAX_STR_LEN];
    int top;
} HashMap;



int N;
HashMap* myMap;



int hash(const char* key) {
    int hash = 0;
    while (*key) hash = (hash * 31 + *key++) % TABLE_SIZE;
    return hash;
}


Node* createNode() {
    Node* new = (Node*) malloc(sizeof(Node));
    new->value[0] = 0;
    new->value[1] = 0;
    new->value[2] = 0;
    new->next = NULL;
    return new;
}


HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    memset(map->buckets, 0, sizeof(map->buckets));
    memset(map->stack, 0, sizeof(map->stack));
    map->top = -1;
    return map;
}


void put(HashMap* map, const char* key, int type, int value) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->value[type] = value;
            return;
        }
        cur = cur->next;
    }
    Node* newNode = createNode();
    strcpy(newNode->key, key);
    map->top += 1;
    strcpy(map->stack[map->top], key);
    newNode->value[type] = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}


int get(HashMap* map, const char* key, int type) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->value[type];
        cur = cur->next;
    }
    return -1; 
}


void freeHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* cur = map->buckets[i];
        while (cur) {
            Node* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(map);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // myMap = createHashMap();
    // char key[MAX_STR_LEN];
    // char type[MAX_STR_LEN];
    // int val;
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%s %s %d", key, type, &val);
    //     if (strcmp(type, "left") == 0) put(myMap, key, 0, val);
    //     else if (strcmp(type, "right") == 0) put(myMap, key, 1, val);
    //     else if (strcmp(type, "any") == 0) put(myMap, key, 2, val);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    myMap = createHashMap();
    char key[MAX_STR_LEN];
    char type[MAX_STR_LEN];
    int val;
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", key, type, &val);
        if (strcmp(type, "left") == 0) put(myMap, key, 0, val);
        else if (strcmp(type, "right") == 0) put(myMap, key, 1, val);
        else if (strcmp(type, "any") == 0) put(myMap, key, 2, val);
    }


    // answer
    int flag = 0;
    int left, right, any;
    int ans = 1;
    for (int i = 0; i <= myMap->top; i++) {
        left = get(myMap, myMap->stack[i], 0);
        right = get(myMap, myMap->stack[i], 1);
        any = get(myMap, myMap->stack[i], 2);
        if (any >= 2 || (left > 1 && (right > 1 || any > 1)) || (right > 1 && (left > 1 || any > 1))) flag = 1;
        
        if (left == 0 && right == 0) ans += 1;
        else ans += max(left, right);
    }
    if (flag) printf("%d\n", ans);
    else printf("impossible\n");


    freeHashMap(myMap);
    return 0;
}