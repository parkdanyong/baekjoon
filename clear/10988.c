/*
    title: 팰린드롬인지 확인하기
    tag: string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100



int main() {
    // input
    char* str = (char*) malloc(sizeof(char)*MAX_LEN+1);
    scanf("%s", str);
    
    
    // answer
    int len = strlen(str);
    int rc = len / 2;
    int flag = 1;
    for (int i = 0; i < rc; i++) {
        if (str[i] != str[len-1-i]) flag = 0;
    }
    printf("%d\n", flag);
    
    
    free(str);
    return 0;
}