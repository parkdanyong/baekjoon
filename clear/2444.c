/*
    title: 별 찍기 - 7
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n-i-1); j++) printf(" ");
        for (int j = 0; j < 2*i+1; j++) printf("*");
        printf("\n");
    }
    for (int i = n-2; i >= 0; i--) {
        for (int j = 0; j < (n-i-1); j++) printf(" ");
        for (int j = 0; j < 2*i+1; j++) printf("*");
        printf("\n");
    }


    return 0;
}