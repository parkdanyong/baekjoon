/*
    title: 알파벳
    tag: graph, DFS, backtracking
*/



#include <stdio.h>
#include <stdlib.h>


int rows, cols;
int size;
char* arr;
int* visited;
int maxDis = 0;


int max(int a, int b) {
    return a > b ? a : b;
}


void backtrack(int pos, int dis) {
    maxDis = max(maxDis, dis);


    char tmp;
    if (pos + 1 < size && pos % cols + 1 < cols) { // right
        if (arr[pos+1] != '0' && visited[arr[pos+1]] == 0) {
            tmp = arr[pos+1];
            arr[pos+1] = '0';
            visited[tmp] = 1;
            backtrack(pos+1, dis+1);
            arr[pos+1] = tmp;
            visited[tmp] = 0;
        }
    }
    if (0 <= pos - 1 && 0 <= pos % cols - 1) { // left
        if (arr[pos-1] != '0' && visited[arr[pos-1]] == 0) {
            tmp = arr[pos-1];
            arr[pos-1] = '0';
            visited[tmp] = 1;
            backtrack(pos-1, dis+1);
            arr[pos-1] = tmp;
            visited[tmp] = 0;
        }
    }
    if (pos + cols < size) { // down
        if (arr[pos+cols] != '0' && visited[arr[pos+cols]] == 0) {
            tmp = arr[pos+cols];
            arr[pos+cols] = '0';
            visited[tmp] = 1;
            backtrack(pos+cols, dis+1);
            arr[pos+cols] = tmp;
            visited[tmp] = 0;
        }
    }
    if (0 <= pos - cols) { // up
        if (arr[pos-cols] != '0' && visited[arr[pos-cols]] == 0) {
            tmp = arr[pos-cols];
            arr[pos-cols] = '0';
            visited[tmp] = 1;
            backtrack(pos-cols, dis+1);
            arr[pos-cols] = tmp;
            visited[tmp] = 0;
        }
    }
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (char*) malloc(sizeof(int)*size);
    // visited = (int*) calloc(150, sizeof(int));
    // char c;
    // for (int i = 0; i < size; i++) {
    //     c = fgetc(file);
    //     if (c == '\n') i--;
    //     else arr[i] = c;
    // }
    // fclose(file); 


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (char*) malloc(sizeof(int)*size);
    visited = (int*) calloc(150, sizeof(int));
    char c;
    for (int i = 0; i < size; i++) {
        c = getchar();
        if (c == '\n') i--;
        else arr[i] = c;
    }


    // init
    visited[arr[0]] = 1;


    // answer
    backtrack(0, 1);
    printf("%d\n", maxDis);


    free(arr);
    free(visited);
    return 0;
}