/*
    title: N-Queen
    tag: brute force, backtracking
*/



#include <stdio.h>
#include <stdlib.h>


int n, size;
int* arr;
int ans;


int removeSpace(int pos, int* stack) {
    int top = -1;
    int cur = pos % n;
    while (cur < size) {
        if (arr[cur] == 0) {
            arr[cur] = 1;
            stack[++top] = cur;
        }
        cur += n;
    }

    cur = pos / n * n;
    for (int i = 0; i < n; i++) {
        if(arr[cur + i] == 0) {
            arr[cur + i] = 1;
            stack[++top] = cur + i;
        }
    }

    cur = pos;
    while (1) {
        if (0 <= cur - n - 1 && 0 <= (cur - n) % n - 1) cur -= (n + 1);
        else break;
    }
    while (1) {
        if (arr[cur] == 0) {
            arr[cur] = 1;
            stack[++top] = cur;
        }
        if (cur + n + 1 < size && cur % n + 1 < n) cur += (n + 1);
        else break;
    }

    cur = pos;
    while (1) {
        if (0 <= cur - n + 1 && cur % n + 1 < n) cur -= (n - 1);
        else break;
    }
    while (1) {
        if (arr[cur] == 0) {
            arr[cur] = 1;
            stack[++top] = cur;
        }
        if (cur + n - 1 < size && 0 <= cur % n - 1) cur += (n - 1);
        else break;
    }
    return top;
}


int restore(int* stack, int top) {
    for (int i = top; i >= 0; i--) {
        arr[stack[i]] = 0;
    }
    return -1;
}


void place(int count) {
    if (count == n) {
        ans += 1;
        return;
    }
    
    int* stack = (int*) malloc(sizeof(int)*size);
    int top = -1;
    int cols = count * n;
    for (int i = 0; i < n; i++) {
        if (arr[cols + i] == 0) {
            // printf("count: %d pos: %d ans: %d\n", count, i, ans);
            top = removeSpace(cols + i, stack);
            // for (int j = 0; j < size; j++) {
            //     printf("%d ", arr[j]);
            //     if ((j+1) % n == 0) printf("\n");
            // }
            place(count+1);
            top = restore(stack, top);
        }
    }
    free(stack);
} 



int main() {
    // input
    scanf("%d", &n);
    size = n * n;


    // init
    arr = (int*) calloc(size, sizeof(int));


    // answer
    ans = 0;
    place(0);
    printf("%d\n", ans);


    free(arr);
    return 0;
}