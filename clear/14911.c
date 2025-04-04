/*
    title: 궁합 쌍 찾기
    tag: brute force, sorting, hash set
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack[10];
int top;
int ans;



int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}



int main() {
    // input
    char* str = (char*) malloc(sizeof(char)*10000000);
    fgets(str, 10000000, stdin);
    int N;
    scanf("%d", &N);
    char* token = strtok(str, " \n");
    top = -1;
    while (token) {
        stack[++top] = atoi(token);
        token = strtok(NULL, " \n");
    }
    qsort(stack, top+1, sizeof(int), compare);
    

    // answer
    ans = 0;
    for (int i = 0; i <= top; i++) {
        if (0 < i && stack[i-1] == stack[i]) continue;
        for (int j = i+1; j <= top; j++) {
            if (i+1 < j && stack[j-1] == stack[j]) continue;
            if (stack[i] + stack[j] == N) {
                printf("%d %d\n", stack[i], stack[j]);
                ans += 1;
            }
        }
    }
    printf("%d\n", ans);


    free(str);
    return 0;
}