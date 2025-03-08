/*
    title: 상수
    tag: math
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>




int main() {
    // input
    char a[4];
    char b[4];
    scanf("%s %s", &a, &b);
    
    
    // answer
    char rev_a[4] = {a[2], a[1], a[0], '\0'};
    char rev_b[4] = {b[2], b[1], b[0], '\0'};
    for (int i = 0; i < 4; i++) {
        a[i] = rev_a[i];
        b[i] = rev_b[i];
    }
    if (atoi(rev_a) > atoi(rev_b)) printf("%s\n", rev_a);
    else printf("%s\n", rev_b);
    
    
    return 0;
}