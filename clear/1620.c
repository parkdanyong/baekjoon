/*
    title: 나는야 포켓몬 마스터 이다솜
    tag: set/map using hash


    1. Using array
    The array must be sorted.
    insert: O(n)
    delete: O(n)
    search: O(logn)


    2. Using tree
    The tree must be sorted.
    insert, delete, search
    O(logn)


    3. Using hash
    insert, delete, search
    average: O(1)
    Worst: O(n)

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 100007




typedef struct Node {
    char key[21];
    int value;
    struct Node* next;
} Node;


typedef struct HashMap {
    Node* buckets[TABLE_SIZE];
} HashMap;


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


int isInteger(const char* str) {
    char* endptr;
    strtol(str, &endptr, 10);

    return *str != '\0' && *endptr == '\0';
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, q;
    // fscanf(file, "%d %d", &n, &q);
    // char** arr = (char**) malloc(sizeof(char*)*(n + 1));
    // HashMap* map = createHashMap();
    // for (int i = 1; i <= n; i++) {
    //     arr[i] = (char*) malloc(sizeof(char)*21);
    //     fscanf(file, "%s", arr[i]);
    //     put(map, arr[i], i);
    // }


    // input
    int n, q;
    scanf("%d %d", &n, &q);
    char** arr = (char**) malloc(sizeof(char*)*(n + 1));
    HashMap* map = createHashMap();
    for (int i = 1; i <= n; i++) {
        arr[i] = (char*) malloc(sizeof(char)*21);
        scanf("%s", arr[i]);
        put(map, arr[i], i);
    }
    


    // answer
    char str[21];
    for (int i = 0; i < q; i++) {
        scanf("%s", str);
        if (isInteger(str)) {
            printf("%s\n", arr[atoi(str)]);
        }
        else {
            printf("%d\n", get(map, str));
        }
    }
    


    for (int i = 1; i <= n; i++) {
        free(arr[i]);
    }
    free(arr);
    freeHashMap(map);
    return 0;
}