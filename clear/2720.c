/*
    title: 세탁소 사장 동혁
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


int T;
int N;



int main() {
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);

        printf("%d ", N / 25);
        N %= 25;
        printf("%d ", N / 10);
        N %= 10;
        printf("%d ", N / 5);
        N %= 5;
        printf("%d\n", N);

    }


    return 0;
}