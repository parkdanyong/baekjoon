/*
    title: 균형잡힌 세상
    tag: string, stack
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*110);
    // char* stack = (char*) malloc(sizeof(char)*110);
    // int top = -1;
    // int len;
    // while (1) {
    //     fgets(str, sizeof(char)*110, file);
    //     len = strlen(str);
    //     if (len == 1 && str[0] == '.') break;

    //     for (int i = 0; i < len; i++) {
    //         if (str[i] == '(' || str[i] == '[') stack[++top] = str[i];
    //         else if ((str[i] == ')' && stack[top] == '(') || (str[i] == ']' && stack[top] == '[')) top -= 1;
    //         else if (str[i] == ')' || str[i] == ']') {
    //             top = 0;
    //             break;
    //         }
    //     }

    //     if (top == -1) printf("yes\n");
    //     else printf("no\n");
    //     top = -1;
    // }
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*110);
    char* stack = (char*) malloc(sizeof(char)*110);
    int top = -1;
    int len;
    while (1) {
        fgets(str, sizeof(char)*110, stdin);
        len = strlen(str);
        if (str[0] == '.') break;

        for (int i = 0; i < len; i++) {
            if (str[i] == '(' || str[i] == '[') stack[++top] = str[i];
            else if (top != -1 && ((str[i] == ')' && stack[top] == '(') || (str[i] == ']' && stack[top] == '['))) top -= 1;
            else if (str[i] == ')' || str[i] == ']') {
                top = 0;
                break;
            }
        }

        if (top == -1) printf("yes\n");
        else printf("no\n");
        top = -1;
    }


    free(str);
    free(stack);
    return 0;
}