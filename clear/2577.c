/*
    title: 숫자의 개수
    tag: math, implement
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
    // input
    int n = 1;
    int tmp;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &tmp);
        n *= tmp;
    }


    // init
    char* str = (char*) malloc(sizeof(char)*20);
    sprintf(str, "%d", n);
    int len = strlen(str);


    // answer
    int* ans = (int*) calloc(10, sizeof(int));
    for (int i = 0; i < len; i++) {
        ans[str[i] - '0'] += 1;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", ans[i]);
    }


    free(ans);
    free(str);
    return 0;
}