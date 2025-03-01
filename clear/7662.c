/*
    title: 이중 우선순위 큐
    tag: Set/Map using Tree, priority queue

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define CANCELED 2147483648


typedef struct MinMaxHeap {
    int* arr;
    int size;
    int count;
}MinMaxHeap;


int min(int a, int b) {
    return a < b ? a : b;
}


int max(int a, int b) {
    return a > b ? a : b;
}


MinMaxHeap* createMinMaxHeap(int size) {
    MinMaxHeap* heap = (MinMaxHeap*) malloc(sizeof(MinMaxHeap));
    heap->arr = (int*) malloc(sizeof(int)*size);
    heap->size = size;
    heap->count = 0;
    return heap;
}


void initHeap(MinMaxHeap* heap) {
    heap->count = 0;
    memset(heap->arr, 0, sizeof(int) * heap->size);
}


int isMinLevel(int i) { // even level: min / odd level: max
    return (int) (log2(i)) % 2 == 0; 
}


void swap(int *a, int *b) { 
    int temp = *a;
    *a = *b;
    *b = temp;
}


int cmpGrandparent(MinMaxHeap* heap, int cur, int weight) {
    int* list = heap->arr;
    int parent = cur / weight;
    if (parent == 0) return cur;
    if (isMinLevel(cur)) { // min level
        if (weight == 2) {
            if (list[cur] > list[parent]) cur = parent;
        }
        else {
            if (list[cur] < list[parent]) cur = parent;
        }
    }
    else { // max level
        if (weight == 2) {
            if (list[cur] < list[parent]) cur = parent; 
        }
        else {
            if (list[cur] > list[parent]) cur = parent; 
        }
    }
    return cur;
}


void insert(MinMaxHeap* heap, int val) {
    if (heap->count == heap->size) return;

    int* list = heap->arr;
    heap->count += 1;
    list[heap->count] = val;

    int cmp;
    int cur = heap->count;
    // compare with parent
    cmp = cmpGrandparent(heap, cur, 2); 
    if (cur != cmp) {
        swap(&list[cur], &list[cmp]);
        cur = cmp;
    }
    // compare with grandparent
    while (cur > 3) {
        cmp = cmpGrandparent(heap, cur, 4); 
        if (cur != cmp) {
            swap(&list[cur], &list[cmp]);
            cur = cmp;
        }
        else break;
    }
}


int cmpChild(MinMaxHeap* heap, int cur) {
    int c = heap->count;
    int* list = heap->arr;
    int child = cur;
    if (isMinLevel(cur)) {
        if (cur * 2 + 1 <= c && list[cur * 2] > list[cur * 2 + 1]) {
            if (list[cur] > list[cur * 2 + 1]) child = cur * 2 + 1;
        }
        else if (cur * 2 <= c) {
            if (list[cur] > list[cur * 2]) child = cur * 2;
        }
    }
    else {
        if (cur * 2 + 1 <= c && list[cur * 2] < list[cur * 2 + 1]) {
            if (list[cur] < list[cur * 2 + 1]) child = cur * 2 + 1;
        }
        else if (cur * 2 <= c) {
            if (list[cur] < list[cur * 2]) child = cur * 2;
        }
    }
    return child;
}


int cmpGrandchild(MinMaxHeap* heap, int cur) {
    int c = heap->count;
    int* list = heap->arr;
    int cmpVal = list[cur];
    int grandChild = cur;
    if (isMinLevel(cur)) {
        if (cur * 4 <= c && list[cur * 4] < cmpVal) {
            grandChild = cur * 4;
            cmpVal = list[cur * 4];
        }
        if (cur * 4 + 1 <= c && list[cur * 4 + 1] < cmpVal) {
            grandChild = cur * 4 + 1;
            cmpVal = list[cur * 4 + 1];
        }
        if (cur * 4 + 2 <= c && list[cur * 4 + 2] < cmpVal) {
            grandChild = cur * 4 + 2;
            cmpVal = list[cur * 4 + 2];
        }
        if (cur * 4 + 3 <= c && list[cur * 4 + 3] < cmpVal) {
            grandChild = cur * 4 + 3;
            cmpVal = list[cur * 4 + 3];
        }
    }
    else {
        if (cur * 4 <= c && list[cur * 4] > cmpVal) {
            grandChild = cur * 4;
            cmpVal = list[cur * 4];
        }
        if (cur * 4 + 1 <= c && list[cur * 4 + 1] > cmpVal) {
            grandChild = cur * 4 + 1;
            cmpVal = list[cur * 4 + 1];
        }
        if (cur * 4 + 2 <= c && list[cur * 4 + 2] > cmpVal) {
            grandChild = cur * 4 + 2;
            cmpVal = list[cur * 4 + 2];
        }
        if (cur * 4 + 3 <= c && list[cur * 4 + 3] > cmpVal) {
            grandChild = cur * 4 + 3;
            cmpVal = list[cur * 4 + 3];
        }
    }
    return grandChild;
}


void delete(MinMaxHeap* heap, double* dest, int delMax) {
    if (heap->count == 0) { // empty
            *dest = CANCELED;
            return;
        } 


    int n;
    int* list = heap->arr;
    if (delMax == 0) { // delete min
        *dest = list[1];
        list[1] = list[heap->count];
        n = 1;
    }
    else { // delete max
        if (heap->count < 3) {
            *dest = heap->arr[heap->count];
            heap->count -= 1;
            return;
        }
        else {
            n = heap->arr[2] > heap->arr[3] ? 2 : 3;
            *dest = heap->arr[n];
            list[n] = list[heap->count];
        }
    }
    heap->count -= 1;


    int c = heap->count;
    int cmp;
    int cur = n;
    while (cur < c) {
        cmp = cmpChild(heap, cur);
        if (cur != cmp) swap(&list[cur], &list[cmp]);
        cmp = cmpGrandchild(heap, cur);
        if (cur != cmp) {
            swap(&list[cur], &list[cmp]);
            cur = cmp;
        }
        else break;
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int t;
    // fscanf(file, "%d", &t);
    // MinMaxHeap* heap = createMinMaxHeap(100);
    // int commandCount;
    // char* command = (char*) malloc(sizeof(char)*100);
    // char* token;
    // double dest;
    // double maxVal;
    // double minVal;
    // for (int i = 0; i < t; i++) {
    //     fscanf(file, "%d%*c", &commandCount);
    //     for (int j = 0; j < commandCount; j++) {
    //         fgets(command, sizeof(char)*100, file);
    //         token = strtok(command, " \n");
    //         if (strcmp(token, "I") == 0) { // insert
    //             token = strtok(NULL, " \n");
    //             insert(heap, atoi(token));
    //         }
    //         else { // delete
    //             token = strtok(NULL, " \n");
    //             if (atoi(token) == 1) { // max
    //                 delete(heap, &dest, 1);
    //             }
    //             else { // min
    //                 delete(heap, &dest, 0);
    //             }
    //         }
    //     }
        

    //     delete(heap, &maxVal, 1);
    //     if (maxVal == CANCELED) printf("EMPTY\n");
    //     else {
    //         delete(heap, &minVal, 0);
    //         if (minVal == CANCELED) printf("%d %d\n", (int) maxVal, (int) maxVal);
    //         else printf("%d %d\n", (int) maxVal, (int) minVal);
    //     }
    //     initHeap(heap);
    // }
    // fclose(file);


    // input
    int t;
    scanf("%d", &t);
    MinMaxHeap* heap = createMinMaxHeap(1000010);
    int commandCount;
    char* command = (char*) malloc(sizeof(char)*100);
    char* token;
    double dest;
    double maxVal;
    double minVal;
    for (int i = 0; i < t; i++) {
        scanf("%d%*c", &commandCount); 
        for (int j = 0; j < commandCount; j++) {
            fgets(command, sizeof(char)*100, stdin);
            token = strtok(command, " \n");
            if (strcmp(token, "I") == 0) { // insert
                token = strtok(NULL, " \n");
                insert(heap, atoi(token));
            }
            else { // delete
                token = strtok(NULL, " \n");
                if (atoi(token) == 1) { // max
                    delete(heap, &dest, 1);
                }
                else { // min
                    delete(heap, &dest, 0);
                }
            }
        }
        

        delete(heap, &maxVal, 1);
        if (maxVal == CANCELED) printf("EMPTY\n");
        else {
            delete(heap, &minVal, 0);
            if (minVal == CANCELED) printf("%d %d\n", (int) maxVal, (int) maxVal);
            else printf("%d %d\n", (int) maxVal, (int) minVal);
        }
        initHeap(heap);
    }



    free(heap->arr);
    free(heap);
    free(command);
    return 0;
}