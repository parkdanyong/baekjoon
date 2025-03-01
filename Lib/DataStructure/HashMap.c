#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 100




typedef struct Node {
    char key[50];
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
void put(HashMap* map, const char* key, int value) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (strcmp(cur->key, key) == 0) {
            cur->value = value; // 키가 존재하면 업데이트
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
    HashMap* map = createHashMap();
    put(map, "apple", 3);
    put(map, "banana", 5);
    put(map, "apple", 10); // 키 업데이트
    printf("Value for 'apple': %d\n", get(map, "apple")); // 출력: 10
    printf("Contains 'banana': %d\n", containsKey(map, "banana")); // 출력: 1
    freeHashMap(map);
    return 0;
}
