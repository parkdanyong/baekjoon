#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


// I use circular queue at this problem.


typedef struct Node {
    int data;
    struct Node* next;
} Node;



Node* create(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("malloc error\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}


void freeAll(Node* node) {
    Node* cur = node;
    Node* tmp;

    while (cur != node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
    free(cur);
}


Node* initQueue(Node* head, int n) {
    Node* tail = head;
    Node* tmp;

    for (int i = 2; i <= n; i++) {
        tmp = create(i);
        if (tmp == NULL) {
            freeAll(head);
            return NULL;
        }
        tail->next = tmp;
        tail = tmp;
    }
    tail->next = head; // link tail -> head

    return tail;
}


int finalCard(Node* head, Node* tail) {
    Node* cur = head;
    Node* end = tail;
    Node* tmp;

    while (cur != end) { // if tail equal head then break
        // pop
        tmp = cur;
        cur = cur->next;
        end->next = cur;
        free(tmp);

        tmp = cur;
        cur = cur->next; // head jump to tail
        end = tmp; // tail should move to pre node
    }
    return cur->data;
}






int main() {
    Node* head = create(1);
    if (head == NULL) return 1;
    Node* tail = NULL;


    int n;
    scanf("%d", &n);
    if (n <= 0) return 1;


    tail = initQueue(head, n);
    printf("%d\n", finalCard(head, tail));



    freeAll(head);
    return 0;
}