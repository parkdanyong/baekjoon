/*
    title: 단어의 개수
    tag: string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // input
    char* str = (char*) malloc(sizeof(char)*1000010);
    fgets(str, sizeof(char)*1000010, stdin);


    // init
    char* token;
    token = strtok(str, " \n");


    // answer
    int ans = 0;
    while (token != NULL) {
        token = strtok(NULL, " \n");
        ans += 1;
    }
    printf("%d\n", ans);


    free(str);
    free(token);
    return 0;
}