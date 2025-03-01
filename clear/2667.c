/*
    title: 단지번호붙이기
    tag: graph, DFS, BFS
*/




#include <stdio.h>
#include <stdlib.h>


int n;
int size;
int* arr;


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


int dfs(int pos) {
    int* stack = (int*) malloc(sizeof(int)*size);
    stack[0] = pos;
    int top = 0;
    arr[pos] = 0; // visited

    int count = 1;
    int cur = 0;
    while (top != -1) {
        // pop
        cur = stack[top--];
        // printf("cur: %d\n", cur);

        // push
        if (cur + 1 < size && cur % n + 1 < n) { // right
            if (arr[cur + 1] == 1) {
                count += 1;
                arr[cur + 1] = 0; // visited
                stack[++top] = cur + 1;
            }
        }
        if (0 <= cur - 1 && 0 <= cur % n - 1) { // left
            if (arr[cur - 1] == 1) {
                count += 1;
                arr[cur - 1] = 0; // visited
                stack[++top] = cur - 1;
            }
        }
        if (0 <= cur - n) { // up
            if (arr[cur - n] == 1) {
                count += 1;
                arr[cur - n] = 0; // visited
                stack[++top] = cur - n;
            }
        }
        if (cur + n < size) { // down
            if (arr[cur + n] == 1) {
                count += 1;
                arr[cur + n] = 0; // visited
                stack[++top] = cur + n;
            }
        }
    }
    // printf("pos: %d count: %d\n", pos, count);

    free(stack);
    return count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // size = n * n;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     arr[i] = fgetc(file);
    //     if (arr[i] == '\n') i--;
    //     else arr[i] -= '0';
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    size = n * n;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        arr[i] = getchar();
        if (arr[i] == '\n') i--;
        else arr[i] -= '0';
    }


    // answer
    int* ans = (int*) malloc(sizeof(int)*size);
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 1) ans[count++] = dfs(i);
    }
    qsort(ans, count, sizeof(int), compare);
    printf("%d\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d\n", ans[i]);
    }


    free(arr);
    free(ans);
    return 0;
}