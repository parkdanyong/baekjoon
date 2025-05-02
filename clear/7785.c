/*
    title: 회사에 있는 사람
    tag: hash
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 1000000
#define MAX_STR_LEN 6



typedef struct Node {
    char key[MAX_STR_LEN];
    int value;
    struct Node* next;
}Node;


typedef struct HashMap {
    Node* table[TABLE_SIZE];
}HashMap;



int N;
HashMap* set;
char** nameList;
int top;



int hash(char* key) {
    int hash = 0;
    while (*key) hash = (hash * 31 + *key++) % TABLE_SIZE;
    return hash;
}


HashMap* createHashMap() {
    HashMap* set = (HashMap*) malloc(sizeof(HashMap));
    memset(set->table, 0, sizeof(set->table));
    return set;
}


void put(HashMap* map, char* key, int value) {
    int index = hash(key);
    Node* cur = map->table[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }
    Node* new = (Node*) malloc(sizeof(Node));
    strcpy(new->key, key);
    new->value = value;
    new->next = map->table[index];
    map->table[index] = new;
}


int get(HashMap* map, char* key) {
    int index = hash(key);
    Node* cur = map->table[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->value;
        cur = cur->next;
    }
    return -1;
}


void removeValue(HashMap* map, char* key) {
    int index = hash(key);
    Node* cur = map->table[index];
    Node* pre = NULL;
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            if (pre) pre->next = cur->next;
            else map->table[index] = cur->next;
            free(cur);
            return;
        }
        pre = cur;
        cur = cur->next;
    }
}


void freeHashMap(HashMap* map) {
    Node* del;
    Node* cur;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cur = map->table[i];
        while (cur) {
            
            del = cur;
            cur = cur->next;
            free(del);
        }
    }
    free(map);
}


void gether() {
    Node* cur;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cur = set->table[i];
        while (cur) {
            nameList[++top] = (char*) malloc(sizeof(char)*MAX_STR_LEN);
            strcpy(nameList[top], cur->key);
            cur = cur->next;
        }
    }
}


int compare(const void* arg1, const void* arg2) {
    char* a = * (char**) arg1;
    char* b = * (char**) arg2;
    return strcmp(b, a);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // set = createHashMap();
    // char name[MAX_STR_LEN];
    // char state[MAX_STR_LEN];
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%s %s", name, state);
    //     if (strcmp(state, "enter") == 0) put(set, name, 1);
    //     else removeValue(set, name);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    set = createHashMap();
    char name[MAX_STR_LEN];
    char state[MAX_STR_LEN];
    for (int i = 0; i < N; i++) {
        scanf("%s %s", name, state);
        if (strcmp(state, "enter") == 0) put(set, name, 1);
        else removeValue(set, name);
    }


    // answer
    nameList = (char**) malloc(sizeof(char*)*N);
    top = -1;
    gether();
    qsort(nameList, top+1, sizeof(char*), compare);
    for (int i = 0; i <= top; i++) {
        printf("%s\n", nameList[i]);
    }



    freeHashMap(set);
    for (int i = 0; i <= top; i++) {
        free(nameList[i]);
    }
    free(nameList);
    return 0;
}