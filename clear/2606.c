/*
    title: 바이러스
    tag: graph, search, DFS, BFS
*/



#include <stdio.h>
#include <stdlib.h>



int DFS(int* metrics, int n, int* visited) {
    int* stack = (int*) malloc(sizeof(int)*n);
    stack[0] = 1; // start node 1
    visited[1] = 1;
    int top = 0;
    int count = 0;
    int cur = 0;

    while (top != -1) {
        // pop
        cur = stack[top--];

        // push
        for (int i = 1; i <= n; i++) {
            if (metrics[cur + i*n] != 0 && visited[metrics[cur + i*n]] == 0) {
                count++;
                visited[metrics[cur + i*n]] = 1;
                stack[++top] = metrics[cur + i*n];
            }
        }
    }
    

    free(stack);
    return  count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, p;
    // fscanf(file, "%d", &n);
    // fscanf(file, "%d", &p);
    // int a, b;
    // int* metrics = (int*) calloc((n + 1)*(n + 1), sizeof(int));
    // for (int i = 0; i < p; i++) {
    //     fscanf(file, "%d %d", &a, &b);
    //     metrics[a + b*n] = b;
    //     metrics[a*n + b] = a;
    // }
    // fclose(file);


    // input
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    int a, b;
    int* metrics = (int*) calloc((n + 1)*(n + 1), sizeof(int));
    for (int i = 0; i < p; i++) {
        scanf("%d %d", &a, &b);
        metrics[a + b*n] = b;
        metrics[a*n + b] = a;
    }


    // init
    int* visited = (int*) calloc(n + 1, sizeof(int));


    // answer
    int ans = 0;
    ans = DFS(metrics, n, visited);
    printf("%d\n", ans);


    free(metrics);
    free(visited);
    return 0;
}
