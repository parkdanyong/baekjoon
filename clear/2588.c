/*
    title: 곱셈
    tag: math
*/



#include <stdio.h>



int main() {
    // input
    int A, B;
    scanf("%d", &A);
    scanf("%d", &B);
    
    
    // answer
    printf("%d\n", A * (B % 10));
    printf("%d\n", A * (B / 10 % 10));
    printf("%d\n", A * (B / 100));
    printf("%d\n", A * B);
    
    
    return 0;
}