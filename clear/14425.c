/*
    title: 문자열 집합
    tag: hash set
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define TABLE_SIZE 10000
#define MAX_STR_LEN 1000



typedef struct Node {
    char key[MAX_STR_LEN];
    int value;
    struct Node* next;
} Node;


typedef struct HashMap {
    Node* buckets[TABLE_SIZE];
} HashMap;



// 해시 함수
int hash(const char* key) {
    int hash = 0;
    while (*key) hash = (hash * 31 + *key++) % TABLE_SIZE;
    return hash;
}


// 맵 초기화
HashMap* createHashMap() {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    memset(map->buckets, 0, sizeof(map->buckets));
    return map;
}


// 키-값 쌍 추가/업데이트
void put(HashMap* map, const char* key) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            return; // 키가 존재하면 return
        }
        cur = cur->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = 1;
    newNode->next = map->buckets[index];
    map->buckets[index] = newNode;
}


// 값 가져오기
int get(HashMap* map, const char* key) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return cur->value;
        cur = cur->next;
    }
    return -1; // 키가 없을 경우
}


// 키 존재 확인
int containsKey(HashMap* map, const char* key) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) return 1;
        cur = cur->next;
    }
    return 0;
}


// 메모리 해제
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


// 테스트
int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // HashMap* set = createHashMap();
    // int n, m;
    // fscanf(file, "%d %d", &n, &m);
    // char str[MAX_STR_LEN];
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%s", str);
    //     put(set, str);
    // }
    // int ans = 0;
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%s", str);
    //     if (containsKey(set, str)) ans += 1;
    // }
    // printf("%d\n", ans);
    // fclose(file);


    // input
    HashMap* set = createHashMap();
    int n, m;
    scanf("%d %d", &n, &m);
    char str[MAX_STR_LEN];
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        put(set, str);
    }


    // answer
    int ans = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        if (containsKey(set, str)) ans += 1;
    }
    printf("%d\n", ans);


    freeHashMap(set);
    return 0;
}
