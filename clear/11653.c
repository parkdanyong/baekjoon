/*
    title: 소인수분해
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // input
    int N;
    scanf("%d", &N);


    // answer
    int div = 2;
    while (N > 1) {
        if (N % div == 0) {
            printf("%d\n", div);
            N /= div;
        }
        else div += 1;
    }


    return 0;
}