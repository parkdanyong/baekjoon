/*
    title: 유기농 배추
    tag: graph, graph search, DFS, BFS
*/



#include <stdio.h>
#include <stdlib.h>


int dfs(int* field, int rows, int cols, int* visited, int start) {
    int* stack = (int*) malloc(sizeof(int)*rows*cols);
    visited[start] = 1;
    stack[0] = start;
    int top = 0;

    int cur = 0;
    while (top != -1) {
        // pop
        cur = stack[top--];

        // push
        if (cur + 1 < rows*cols && cur % cols + 1 < cols) { // right
            if (field[cur + 1] == 1 && visited[cur + 1] == 0) {
                stack[++top] = cur + 1;
                visited[cur + 1] = 1;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % cols - 1) { // left
            if (field[cur - 1] == 1 && visited[cur - 1] == 0) {
                stack[++top] = cur - 1;
                visited[cur - 1] = 1;
            }
        }
        if (0 <= cur - cols) { // up
            if (field[cur - cols] == 1 && visited[cur - cols] == 0) { 
                stack[++top] = cur - cols;
                visited[cur - cols] = 1;
            }
        }
        if (cur + cols < rows*cols) { // down
            if (field[cur + cols] == 1 && visited[cur + cols] == 0) {
                stack[++top] = cur + cols;
                visited[cur + cols] = 1;
            }
        }
    }


    free(stack);
    return 1;
}



void clear(int* field) {
    for (int i = 0; i < 2500; i++) {
        field[i] = 0;
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    int n;
    // fscanf(file, "%d", &n);
    scanf("%d", &n);
    

    // init
    int* visited = (int*) calloc(2500, sizeof(int));
    int* field = (int*) calloc(2500, sizeof(int));
    int rows, cols, k;
    int row, col;


    // answer 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        // fscanf(file, "%d %d %d", &cols, &rows, &k);
        scanf("%d %d %d", &cols, &rows, &k);
        for (int j = 0; j < k; j++) {
            // fscanf(file, "%d %d", &col, &row);
            scanf("%d %d", &col, &row);
            field[row*cols + col] = 1;
        }


        for (int j = 0; j < 2500; j++) {
            if (field[j] == 1 && visited[j] == 0) {
                ans += dfs(field, rows, cols, visited, j);
            }
        }
        

        printf("%d\n", ans);
        ans = 0;
        clear(visited);
        clear(field);      
    } 
    



    // fclose(file);
    free(visited);
    free(field);
    return 0;
}