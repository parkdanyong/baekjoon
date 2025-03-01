#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct HashSet {
    Node* buckets[TABLE_SIZE];
} HashSet;

// 해시 함수
int hash(int value) {
    return value % TABLE_SIZE;
}

// 해시 집합 초기화
HashSet* createHashSet() {
    HashSet* set = (HashSet*)malloc(sizeof(HashSet));
    memset(set->buckets, 0, sizeof(set->buckets));
    return set;
}

// 값 추가
void add(HashSet* set, int value) {
    int index = hash(value);
    Node* cur = set->buckets[index];
    while (cur) {
        if (cur->value == value) return; // 중복 방지
        cur = cur->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = set->buckets[index];
    set->buckets[index] = newNode;
}

// 값 존재 확인
int contains(HashSet* set, int value) {
    int index = hash(value);
    Node* cur = set->buckets[index];
    while (cur) {
        if (cur->value == value) return 1;
        cur = cur->next;
    }
    return 0;
}

// 값 제거
void removeValue(HashSet* set, int value) {
    int index = hash(value);
    Node* cur = set->buckets[index];
    Node* prev = NULL;
    while (cur) {
        if (cur->value == value) {
            if (prev) prev->next = cur->next;
            else set->buckets[index] = cur->next;
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

// 메모리 해제
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

// 테스트
int main() {
    HashSet* set = createHashSet();
    add(set, 5);
    add(set, 10);
    add(set, 5); // 중복 추가 방지
    printf("Contains 5: %d\n", contains(set, 5)); // 출력: 1
    printf("Contains 15: %d\n", contains(set, 15)); // 출력: 0
    removeValue(set, 5);
    printf("Contains 5 after removal: %d\n", contains(set, 5)); // 출력: 0
    freeHashSet(set);
    return 0;
}
