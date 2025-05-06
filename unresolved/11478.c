/*
    title: 서로 다른 부분 문자열의 개수
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ALPHABET_SIZE 26


typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int is_end;
} TrieNode;


TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    node->is_end = 0;
    return node;
}


int insert(TrieNode* root, const char* str) {
    TrieNode* cur = root;
    int is_new = 0;
    for (int i = 0; str[i]; i++) {
        int idx = str[i] - 'a';
        if (!cur->children[idx]) {
            cur->children[idx] = createNode();
            is_new = 1; 
        }
        cur = cur->children[idx];
    }
    return is_new;
}


void freeTrie(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i])
            freeTrie(root->children[i]);
    }
    free(root);
}


int main() {
    // input
    char str[1001];
    scanf("%s", str);
    int len = strlen(str);


    // answer
    TrieNode* root = createNode();
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            char temp[1001];
            strncpy(temp, str + i, j - i + 1);
            temp[j - i + 1] = '\0';
            if (insert(root, temp)) {
                count++;
            }
        }
    }
    printf("%d\n", count);


    freeTrie(root);
    return 0;
}
