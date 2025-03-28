/*
    title: 약수들의 합
    tag: math
*/



#include <stdio.h>
#include <stdlib.h>


#define STACK_SIZE 100000


int main() {
    // init
    int N;
    int* stack = (int*) malloc(sizeof(int)*STACK_SIZE);
    int top = -1;


    // input
    int cmp = 0;
    int sum = 0;
    while (1) {
        scanf("%d", &N);
        if (N == -1) break;

        // answer
        top = -1;
        cmp = 1;
        sum = 0;
        while (1) {
            if (N <= cmp) break;

            if (N % cmp == 0) {
                sum += cmp;
                stack[++top] = cmp;
            }
            cmp += 1;
        }
        printf("%d ", N);
        if (sum == N) {
            printf("= ");
            for (int i = 0; i <= top; i++) {
                printf("%d ", stack[i]);
                if (i != top) printf("+ ");
            }
            printf("\n");
        }
        else printf("is NOT perfect.\n");
    }


    free(stack);
    return 0;
}