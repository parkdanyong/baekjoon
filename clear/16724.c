/*
    title: 피리 부는 사나이
    tag: graph, DFS, Disjoint Set
*/



#include <stdio.h>
#include <stdlib.h>


int rows, cols, size;
char* graph;
int* set;
int* stack;
int top;


int nextPos(int pos) {
    if (graph[pos] == 'R') return pos + 1;
    else if (graph[pos] == 'L') return pos - 1;
    else if (graph[pos] == 'U') return pos - cols;
    else if (graph[pos] == 'D') return pos + cols;
}


void dfs(int pos, int n) {
    set[pos] = n;
    stack[0] = pos;
    top = 0;
    
    int next;
    int cur;
    while (top > -1) {
        // pop
        cur = stack[top--];

        // push
        next = nextPos(cur);
        if (set[next] == 0) {
            stack[++top] = next;
            set[next] = n;
        }
        if (cur + 1 < size && cur % cols + 1 < cols) { // right
            if (set[cur + 1] == 0 && nextPos(cur + 1) == cur) {
                stack[++top] = cur + 1;
                set[cur + 1] = n;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (set[cur - 1] == 0 && nextPos(cur - 1) == cur) {
                stack[++top] = cur - 1;
                set[cur - 1] = n;
            }
        }
        if (0 <= cur - cols) { // up
            if (set[cur - cols] == 0 && nextPos(cur - cols) == cur) {
                stack[++top] = cur - cols;
                set[cur - cols] = n;
            }
        }
        if (cur + cols < size) { // down
            if (set[cur + cols] == 0 && nextPos(cur + cols) == cur) {
                stack[++top] = cur + cols;
                set[cur + cols] = n;
            }
        }
    }
}   


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // graph = (char*) malloc(sizeof(char)*size);
    // for (int i = 0; i < size; i++) {
    //     graph[i] = fgetc(file);
    //     if (graph[i] == '\n') i -= 1;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    graph = (char*) malloc(sizeof(char)*size);
    for (int i = 0; i < size; i++) {
        graph[i] = fgetc(stdin);
        if (graph[i] == '\n') i -= 1;
    }


    // init
    set = (int*) calloc(size, sizeof(int));
    stack = (int*) malloc(sizeof(int)*size);


    // answer
    int ans = 0;
    for (int i = 0; i < size; i++) {
        if (set[i] == 0) dfs(i, ++ans);
    }
    printf("%d\n", ans);
    

    free(graph);
    free(set);
    free(stack);
    return 0;
}