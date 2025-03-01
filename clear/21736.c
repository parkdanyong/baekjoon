/*
    title: 헌내기는 친구가 필요해
    tag: graph, graph search, BFS, DFS
*/



#include <stdio.h>
#include <stdlib.h>


int rows, cols;
int size;
char* arr;


int dfs(int pos) {
    int* visited = (int*) calloc(size, sizeof(int));
    int* stack = (int*) malloc(sizeof(int)*size);
    visited[pos] = 1;
    stack[0] = pos;
    int top = 0;

    int meeting = 0;
    int cur;
    while (top != -1) {
        // pop
        cur = stack[top--];
        if (arr[cur] == 'P') meeting += 1;
        // printf("cur: %d meeting: %d\n", cur, meeting);

        // push
        if (cur + 1 < size && cur % cols + 1 < cols) { // right
            if (arr[cur + 1] != 'X' && visited[cur + 1] == 0) {
                stack[++top] = cur + 1;
                visited[cur + 1] = 1;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (arr[cur - 1] != 'X' && visited[cur - 1] == 0) {
                stack[++top] = cur - 1;
                visited[cur - 1] = 1;
            }
        }
        if (0 <= cur - cols) { // up
            if (arr[cur - cols] != 'X' && visited[cur - cols] == 0) {
                stack[++top] = cur - cols;
                visited[cur - cols] = 1;
            }
        }
        if (cur + cols < size) { // down
            if (arr[cur + cols] != 'X' && visited[cur + cols] == 0) {
                stack[++top] = cur + cols;
                visited[cur + cols] = 1;
            }
        }
    }


    free(visited);
    free(stack);
    return meeting;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (char*) malloc(sizeof(char)*size);
    // int pos;
    // for (int i = 0; i < size; i++) {
    //     if (i % cols == 0) fscanf(file, " %c", &arr[i]);
    //     else fscanf(file, "%c", &arr[i]);
    //     if (arr[i] == 'I') pos = i;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (char*) malloc(sizeof(char)*size);
    int pos;
    for (int i = 0; i < size; i++) {
        if (i % cols == 0) scanf(" %c", &arr[i]);
        else scanf("%c", &arr[i]);
        if (arr[i] == 'I') pos = i;
    }


    // answer
    int ans = dfs(pos);
    if (ans) printf("%d\n", ans);
    else printf("TT\n");


    free(arr);
    return 0;
}