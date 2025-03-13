/*
    title: 텀 프로젝트
    tag: graph, DFS
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 100000


int T, N;
int* arr;
int* cSet;
int* visited;
int* stack;
int time_stamp, top;



int dfs(int ver) {
    top = -1;
    int rv = 0;
    int cur = ver;
    while (1) {
        visited[cur] = time_stamp;
        stack[++top] = cur;
        cur = arr[cur];
        if (visited[cur] == time_stamp) {
            if (cSet[cur] != time_stamp) {
                while (top > -1) {
                    rv += 1;
                    cSet[stack[top]] = time_stamp;
                    if (stack[top--] == cur) break;
                }
            }
            break;
        }
    }
    
    while (top > -1) {
        cSet[stack[top--]] = time_stamp;
    }
    return rv;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // arr = (int*) malloc(sizeof(int)*(MAX_SIZE+1));
    // cSet = (int*) calloc(MAX_SIZE+1, sizeof(int));
    // visited = (int*) calloc(MAX_SIZE+1, sizeof(int));
    // stack = (int*) malloc(sizeof(int)*(MAX_SIZE+1));
    // time_stamp = 1;
    // int ans = 0;
    // fscanf(file, "%d", &T);
    // for (int i = 1; i <= T; i++) {
    //     fscanf(file, "%d", &N);
    //     for (int j = 1; j <= N; j++) {
    //         fscanf(file, "%d", &arr[j]);
    //     }

    //     ans = 0;
    //     for (int j = 1; j <= N; j++) {
    //         if (cSet[j] != time_stamp) ans += dfs(j); 
    //     }
    //     time_stamp += 1;
    //     printf("%d\n", N-ans);
    // }
    // fclose(file);


    // init
    arr = (int*) malloc(sizeof(int)*(MAX_SIZE+1));
    cSet = (int*) calloc(MAX_SIZE+1, sizeof(int));
    visited = (int*) calloc(MAX_SIZE+1, sizeof(int));
    stack = (int*) malloc(sizeof(int)*(MAX_SIZE+1));
    time_stamp = 1;


    // input
    int ans = 0;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d", &N);
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[j]);
        }

        // answer
        ans = 0;
        for (int j = 1; j <= N; j++) {
            if (cSet[j] != time_stamp) ans += dfs(j); 
        }
        time_stamp += 1;
        printf("%d\n", N-ans);
    }


    free(arr);
    free(cSet);
    free(visited);
    free(stack);
    return 0;
}