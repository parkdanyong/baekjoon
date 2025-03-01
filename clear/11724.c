/*
    title: 연결 요소의 개수
    tag: graph, DFS, BFS
*/



#include <stdio.h>
#include <stdlib.h>


int dfs(int* graph, int n, int* visited, int start) {
    int* stack = (int*) malloc(sizeof(int)*(n));
    visited[start] = 1;
    stack[0] = start;
    int top = 0;

    int cur = 0;
    while (top != -1) { 
        // pop
        cur = stack[top--];

        // push
        for (int i = 1; i <= n; i++) {
            if (graph[i*(n+1) + cur] == 1 && visited[i] == 0) {
                visited[i] = 1;
                stack[++top] = i;
            }
        }
    }
    
    free(stack);
    return 1;
}





int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, e;
    // fscanf(file, "%d %d", &n, &e);
    // int n1, n2;
    // int* graph = (int*) calloc((n+1)*(n+1), sizeof(int));
    // for (int i = 0; i < e; i++) {
    //     fscanf(file, "%d %d", &n1, &n2);
    //     graph[n1 * (n+1) + n2] = 1;
    //     graph[n2 * (n+1) + n1] = 1;
    // }
    // fclose(file);


    // input    
    int n, e;
    scanf("%d %d", &n, &e);
    int n1, n2;
    int* graph = (int*) calloc((n+1)*(n+1), sizeof(int));
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &n1, &n2);
        graph[n1 * (n+1) + n2] = 1;
        graph[n2 * (n+1) + n1] = 1;
    }


    // init
    int* visited = (int*) calloc(n + 1, sizeof(int));


    // answer
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 0) {
            ans += dfs(graph, n, visited, i);
        }
    }
    printf("%d\n", ans);



    free(graph);
    free(visited);
    return 0;
}