/*
    title: 파이프 옮기기 1
    tag: graph, dp
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_CASE 1000000


typedef struct Node {
    int pos;
    int state;
}node;


int n, size;
int* arr;


int dfs(int pos) {
    node* stack = (node*) malloc(sizeof(node)*MAX_CASE);
    stack[0].pos = pos;
    stack[0].state = 0;
    int top = 0;

    int count = 0;
    node cur;
    while (top != -1) {
        // pop
        cur = stack[top--];
        // printf("pos: %d state: %d\n", cur.pos, cur.state);
        if (cur.pos == size - 1) count += 1;

        // push
        if (cur.state != 1 && cur.pos + 1 < size && cur.pos % n + 1 < n && arr[cur.pos + 1] == 0) { 
            top += 1;
            stack[top].pos = cur.pos + 1;
            stack[top].state = 0;
        }
        if (cur.state != 0 && cur.pos + n < size && arr[cur.pos + n] == 0) {
            top += 1;
            stack[top].pos = cur.pos + n;
            stack[top].state = 1;
        }
        if (cur.pos + n + 1 < size && cur.pos % n + 1 < n && arr[cur.pos + n + 1] == 0 && arr[cur.pos + n] == 0 && arr[cur.pos + 1] == 0) {
            top += 1;
            stack[top].pos = cur.pos + n + 1;
            stack[top].state = 2;
        }
    }
    
    free(stack);
    return count;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // size = n * n;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    size = n * n;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int ans = dfs(1);
    printf("%d\n", ans);


    free(arr);
    return 0;
}