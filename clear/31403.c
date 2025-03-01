/*
    title: A + B - C
    tag: string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    // input
    char a[10];
    char b[10];
    char c[10];
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);


    // answer
    printf("%d\n", atoi(a) + atoi(b) - atoi(c));
    printf("%d\n", atoi(strcat(a, b)) - atoi(c));
    
    
    return 0;
}