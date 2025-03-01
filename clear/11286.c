/*
    title: 절댓값 힙
    tag: data structure, priority queue, heap
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Heap {
    int* arr;
    int size;
    int count;
}heap;


heap* createHeap(int size) {
    heap* queue = (heap*) malloc(sizeof(heap));
    queue->arr = (int*) malloc(sizeof(int)*size);
    queue->size = size;
    queue->count = 0;

    return queue;
}


void changeElement(heap* queue, int e1, int e2) {
    int tmp = queue->arr[e1];
    queue->arr[e1] = queue->arr[e2];
    queue->arr[e2] = tmp;
}


void append(heap* queue, int val) {
    if (queue->count + 1 == queue->size) return;

    queue->count += 1;
    queue->arr[queue->count] = val;

    int parent = 0;
    int cur = queue->count;
    while (1 < cur) {
        parent = cur / 2;
        if (abs(queue->arr[cur]) < abs(queue->arr[parent])) changeElement(queue, cur, parent);
        else if (abs(queue->arr[cur]) == abs(queue->arr[parent])) {
            if (queue->arr[cur] < queue->arr[parent]) changeElement(queue, cur, parent);
            else break;
        }
        else break;
        cur = parent;
    }
}


void delete(heap* queue, int* des) {
    if (queue->count == 0) {
        *des = 0;
        return;   
    }
    
    *des = queue->arr[1];
    queue->arr[1] = queue->arr[queue->count];
    queue->count -= 1;

    int count = queue->count;
    int child = 0;
    int cur = 1;
    while (cur < count) {
        if (cur * 2 + 1 <= count) { // has two childs
            if (abs(queue->arr[cur * 2]) < abs(queue->arr[cur * 2 + 1])) { // left child
                if (abs(queue->arr[cur * 2]) < abs(queue->arr[cur])) changeElement(queue, cur * 2, cur);
                else if (abs(queue->arr[cur * 2]) == abs(queue->arr[cur])) { // equal abs
                    if (queue->arr[cur * 2] < queue->arr[cur]) changeElement(queue, cur * 2, cur);
                    else break;
                }
                else break;
                cur = cur * 2;
            }
            else if (abs(queue->arr[cur * 2]) > abs(queue->arr[cur * 2 + 1])) { // right child
                if (abs(queue->arr[cur * 2 + 1]) < abs(queue->arr[cur])) changeElement(queue, cur * 2 + 1, cur);
                else if (abs(queue->arr[cur * 2 + 1]) == abs(queue->arr[cur])) { // equal abs
                    if (queue->arr[cur * 2 + 1] < queue->arr[cur]) changeElement(queue, cur * 2 + 1, cur);
                    else break;
                }
                else break;
                cur = cur * 2 + 1;
            }
            else { // equal abs
                if (queue->arr[cur * 2] <= queue->arr[cur * 2 + 1]) { // left child
                    if (abs(queue->arr[cur * 2]) < abs(queue->arr[cur])) changeElement(queue, cur * 2, cur);
                    else if (abs(queue->arr[cur * 2]) == abs(queue->arr[cur])) { // equal abs
                        if (queue->arr[cur * 2] < queue->arr[cur]) changeElement(queue, cur * 2, cur);
                        else break;
                    }
                    else break;
                    cur = cur * 2;
                }
                else { // right child
                    if (abs(queue->arr[cur * 2 + 1]) < abs(queue->arr[cur])) changeElement(queue, cur * 2 + 1, cur);
                    else if (abs(queue->arr[cur * 2 + 1]) == abs(queue->arr[cur])) { // equal abs
                        if (queue->arr[cur * 2 + 1] < queue->arr[cur]) changeElement(queue, cur * 2 + 1, cur);
                        else break;
                    }
                    else break;
                    cur = cur * 2 + 1;
                }
            }
        }
        else if (cur * 2 <= count) { // has one child
            if (abs(queue->arr[cur * 2]) < abs(queue->arr[cur])) changeElement(queue, cur * 2, cur);
            else if (abs(queue->arr[cur * 2]) == abs(queue->arr[cur])) { // equal abs
                if (queue->arr[cur * 2] < queue->arr[cur]) changeElement(queue, cur * 2, cur);
                else break;
            }
            else break;
            cur = cur * 2;
        }
        else break; // no child
    }    
} 



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // heap* queue = createHeap(n+10);
    // int cmd = 0;
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &cmd);
    //     if (cmd == 0) {
    //         delete(queue, &cmd);
    //         printf("%d\n", cmd);
    //     }
    //     else {
    //         append(queue, cmd);
    //     }
    // }
    // fclose(file);


    // input
        int n;
    scanf("%d", &n);
    heap* queue = createHeap(n+10);
    int cmd = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &cmd);
        if (cmd == 0) {
            delete(queue, &cmd);
            printf("%d\n", cmd);
        }
        else {
            append(queue, cmd);
        }
    }


    free(queue->arr);
    free(queue);
    return 0;
}