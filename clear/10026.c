/*
    title: 적록색약
    tag: graph, BFS, DFS
*/



#include <stdio.h>
#include <stdlib.h>


int n;
int size;
char* arr;



int RG_ColorBlindness(int pos, int* visited) {
    int* stack = (int*) malloc(sizeof(int)*size);
    stack[0] = pos;
    int top = 0;
    visited[pos] = 1;
    char color1 = arr[pos];
    char color2 = color1;
    if (color1 == 'R') color2 = 'G';
    if (color1 == 'G') color2 = 'R';


    

    int cur = 0;
    while (top != -1) {
        // pop
        cur = stack[top--];

        // push
        if (cur + 1 < size && cur % n + 1 < n) { // right
            if ((arr[cur + 1] == color1 || arr[cur + 1] == color2) && visited[cur + 1] == 0) {
                stack[++top] = cur + 1;
                visited[cur + 1] = 1;
            }
        } 
        if (0 <= cur - 1 && 0 <= cur % n -1) { // left
            if ((arr[cur - 1] == color1 || arr[cur - 1] == color2) && visited[cur - 1] == 0) {
                stack[++top] = cur - 1;
                visited[cur - 1] = 1;
            }
        } 
        if (0 <= cur - n) { // up
            if ((arr[cur - n] == color1 || arr[cur - n] == color2) && visited[cur - n] == 0) {
                stack[++top] = cur - n;
                visited[cur - n] = 1;
            }
        } 
        if (cur + n < size) { // down
            if ((arr[cur + n] == color1 || arr[cur + n] == color2) && visited[cur + n] == 0) {
                stack[++top] = cur + n;
                visited[cur + n] = 1;
            }
        } 
    }

    return 1;
}   


int dfs(int pos, int* visited) {
    int* stack = (int*) malloc(sizeof(int)*size);
    stack[0] = pos;
    int top = 0;
    visited[pos] = 1;
    char color = arr[pos];

    int cur = 0;
    while (top != -1) {
        // pop
        cur = stack[top--];

        // push
        if (cur + 1 < size && cur % n + 1 < n) { // right
            if (arr[cur + 1] == color && visited[cur + 1] == 0) {
                stack[++top] = cur + 1;
                visited[cur + 1] = 1;
            }
        } 
        if (0 <= cur - 1 && 0 <= cur % n -1) { // left
            if (arr[cur - 1] == color && visited[cur - 1] == 0) {
                stack[++top] = cur - 1;
                visited[cur - 1] = 1;
            }
        } 
        if (0 <= cur - n) { // up
            if (arr[cur - n] == color && visited[cur - n] == 0) {
                stack[++top] = cur - n;
                visited[cur - n] = 1;
            }
        } 
        if (cur + n < size) { // down
            if (arr[cur + n] == color && visited[cur + n] == 0) {
                stack[++top] = cur + n;
                visited[cur + n] = 1;
            }
        } 
    }

    return 1;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // size = n * n;
    // arr = (char*) malloc(sizeof(char)*size);
    // for (int i = 0; i < size; i++) {
    //     arr[i] = fgetc(file);
    //     if (arr[i] == '\n') i--;
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    size = n * n;
    arr = (char*) malloc(sizeof(char)*size);
    for (int i = 0; i < size; i++) {
        arr[i] = getchar();
        if (arr[i] == '\n') i--;
    }


    // init
    int* visited = (int*) calloc(size, sizeof(int));


    // answer
    int ans = 0;
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) ans += dfs(i, visited);
    }
    printf("%d ", ans);
    ans = 0;
    for (int i = 0; i < size; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        if (visited[i] == 0) ans += RG_ColorBlindness(i, visited);
    }
    printf("%d\n", ans);


    free(arr);
    free(visited);
    return 0;
}