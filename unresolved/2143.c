/*
    title: 두 배열의 합
    tag: sub-sum, hash, binary search
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define TABLE_SIZE 2000003


typedef long long ll;


typedef struct Node {
    ll key;
    ll count;
    struct Node* next;
}Node;


typedef struct HashMap {
    Node* buckets[TABLE_SIZE];
}HashMap;




ll T;
int a, b;
int* A;
int* B;
ll* subSum_A;
ll* subSum_B;
int len_a;
int len_b;
HashMap* hm;




int hash(ll key) {
    if (key < 0) key = -key;
    return key % TABLE_SIZE; 
}


HashMap* createHashMap() {
    HashMap* map = (HashMap*) malloc(sizeof(HashMap));
    memset(map->buckets, 0, sizeof(map->buckets));
    return map;
}


void add(HashMap* map, ll key) {
    ll index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (cur->key == key) {
            cur->count += 1;
            return;
        }
        cur = cur->next;
    }
    Node* new = (Node*) malloc(sizeof(Node));
    new->key = key;
    new->count = 1;
    new->next = map->buckets[index];
    map->buckets[index] = new;
}


ll getCount(HashMap* map, ll key) {
    int index = hash(key);
    Node* cur = map->buckets[index];
    while (cur) {
        if (cur->key == key) return cur->count;
        cur = cur->next;
    }
    return 0;
}


void freeHashMap(HashMap* map) {
    Node* cur;
    Node* del;
    for (int i = 0; i < TABLE_SIZE; i++) {
        cur = map->buckets[i];
        while (cur) {
            del = cur;
            cur = cur->next;
            free(del);
        }
    }
    free(map); 
}


void initSubSum() {
    subSum_A = (ll*) malloc(sizeof(ll)*a*a);
    subSum_B = (ll*) malloc(sizeof(ll)*b*b);
    len_a = 0;
    len_b = 0;
    ll sum = 0;
    for (int i = 0; i < a; i++) {
        sum = 0;
        for (int j = i; j < a; j++) {
            sum += A[j];
            subSum_A[len_a++] = sum;
        }
    }
    for (int i = 0; i < b; i++) {
        sum = 0;
        for (int j = i; j < b; j++) {
            sum += B[j];
            subSum_B[len_b++] = sum;
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%lld", &T);
    // fscanf(file, "%d", &a);
    // A = (int*) malloc(sizeof(int)*a);
    // for (int i = 0; i < a; i++) {
    //     fscanf(file, "%d", &A[i]);
    // }
    // fscanf(file, "%d", &b);
    // B = (int*) malloc(sizeof(int)*b);
    // for (int i = 0; i < b; i++) {
    //     fscanf(file, "%d", &B[i]);
    // }
    // initSubSum();
    // hm = createHashMap();
    // for (int i = 0; i < len_a; i++) {
    //     add(hm, subSum_A[i]);
    // }
    // int ans = 0;
    // for (int i = 0; i < len_b; i++) {
    //     ans += getCount(hm, T-subSum_B[i]);
    // }
    // printf("%d\n", ans);
    // fclose(file);


    // input
    scanf("%lld", &T);
    scanf("%d", &a);
    A = (int*) malloc(sizeof(int)*a);
    for (int i = 0; i < a; i++) {
        scanf("%d", &A[i]);
    }
    scanf("%d", &b);
    B = (int*) malloc(sizeof(int)*b);
    for (int i = 0; i < b; i++) {
        scanf("%d", &B[i]);
    }


    // init
    initSubSum();
    hm = createHashMap();
    for (int i = 0; i < len_a; i++) {
        add(hm, subSum_A[i]);
    }


    // answer
    ll ans = 0;
    for (int i = 0; i < len_b; i++) {
        ans += getCount(hm, T-subSum_B[i]);
    }
    printf("%lld\n", ans);


    free(A);
    free(B);
    free(subSum_A);
    free(subSum_B);
    freeHashMap(hm);
    return 0;
}