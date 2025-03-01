/*
    title: 후위 표기식
    tag: stack
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_MAX_LENGTH 101



int main() {
    // input
    char* str = (char*) malloc(sizeof(char)*STRING_MAX_LENGTH);
    scanf("%s", str);


    // answer
    int len = strlen(str);
    char* stack = (char*) malloc(sizeof(char)*STRING_MAX_LENGTH);
    int top = -1;
    char c;
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') stack[++top] = str[i];
        else if (str[i] == ')') {
            while (top != -1) {
                c = stack[top--];
                if (c == '(') break;
                printf("%c", c);
            }
        }
        else if (str[i] == '*' || str[i] == '/') {
            while (top != -1) {
                c = stack[top--];
                if (c == '+' || c == '-' || c == '(') {
                    stack[++top] = c;
                    break;
                }
                printf("%c", c);
            }
            stack[++top] = str[i];
        }
        else if (str[i] == '+' || str[i] == '-') {
            while (top != -1) {
                c = stack[top--];
                if (c == '(') {
                    stack[++top] = c;
                    break;
                }
                printf("%c", c);
            }
            stack[++top] = str[i];
        }
        else printf("%c", str[i]);
    }
    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");


    free(str);
    free(stack);
    return 0;
}