/*
    title: 문자열 폭발
    tag: stack, string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_MAX_LENGTH 1000001
#define PATTERN_MAX_LENGTH 37


typedef struct Node {
    char c;
    int p;
}node;


int main() {
    // FILE* file = fopen("inputFIle.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*STRING_MAX_LENGTH);
    // char* pattern = (char*) malloc(sizeof(char)*PATTERN_MAX_LENGTH);
    // fscanf(file, "%s", str);
    // fscanf(file, "%s", pattern);
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*STRING_MAX_LENGTH);
    char* pattern = (char*) malloc(sizeof(char)*PATTERN_MAX_LENGTH);
    scanf("%s", str);
    scanf("%s", pattern);


    // init
    int strLen = strlen(str);
    int patternLen = strlen(pattern);
    node* stack = (node*) malloc(sizeof(node)*STRING_MAX_LENGTH);
    int top = -1;
    

    // answer
    int count = 0;
    for (int i = 0; i < strLen; i++) {
        top += 1;
        stack[top].c = str[i];
        if (str[i] == pattern[count]) count += 1;
        else if (str[i] == pattern[0]) count = 1;
        else count = 0;
        stack[top].p = count;

        if (count == patternLen) {
            top -= patternLen;
            if (top == -1) count = 0;
            else count = stack[top].p;
        }
    }

    if (top == -1) printf("FRULA\n");
    else {
        for (int i = 0; i <= top; i++) {
            printf("%c", stack[i].c);
        }
        printf("\n");
    }
    

    free(str);
    free(pattern);
    free(stack);
    return 0;
}