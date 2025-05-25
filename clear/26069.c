/*
    title: 붙임성 좋은 총총이
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 100
#define MAX_STR_LEN 30


typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;


typedef struct HashMap {
    Node* buckets[TABLE_SIZE];
} HashMap;


int N;
HashMap* myMap;



int hash(const char* key) {
    int hash = 0;
    while (*key) hash = (hash * 31 + *key++) % TABLE_SIZE;
    return hash;
}


HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    memset(map->buckets, 0, sizeof(map->buckets));
    return map;
}


void put(HashMap* map, const char* key, int value) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->value = value; 
            return;
        }
        cur = cur->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}


int get(HashMap* map, const char* key) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->value;
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
    // input
    scanf("%d", &N);
    myMap = createHashMap();
    char name1[MAX_STR_LEN];
    char name2[MAX_STR_LEN];
    put(myMap, "ChongChong", 1);
    int ans = 1, v1, v2;
    for (int i = 0; i < N; i++) {
        scanf("%s %s", name1, name2);
        v1 = get(myMap, name1);
        v2 = get(myMap, name2);

        
        if (v1 == 1 || v2 == 1) {
            if (v1 != 1) {
                put(myMap, name1, 1);
                ans += 1;
            }
            if (v2 != 1) {
                put(myMap, name2, 1);
                ans += 1;
            }
        }
        else {
            if (v1 == -1) put(myMap, name1, 0);
            if (v2 == -1) put(myMap, name2, 0);
        }
    }
    printf("%d\n", ans);


    freeHashMap(myMap);
    return 0;
}