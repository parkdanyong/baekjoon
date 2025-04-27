/*
    title: 스택 2
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 2000000


int N;
int top;
int* stack;



int main() {
    // input
    scanf("%d", &N);
    top = -1;
    stack = (int*) malloc(sizeof(int)*STACK_SIZE);
    int command;
    for (int i = 0; i < N; i++) {
        scanf("%d", &command);
        if (command == 1) {
            scanf("%d", &command);
            stack[++top] = command;
        }
        else if (command == 2) {
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top--]);
        }
        else if (command == 3) printf("%d\n", top + 1);
        else if (command == 4) top == -1 ? printf("1\n") : printf("0\n");
        else if (command == 5) {
            if (top == -1) printf("-1\n");
            else printf("%d\n", stack[top]);
        }
    }


    free(stack);
    return 0;
}