/*
    title: ACM 호텔
    tag: implement, math
*/



#include <stdio.h>



int main() { 
    // input
    int t;
    scanf("%d", &t);
    int h, w, n;
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d", &h, &w, &n);
        printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
    }


    return 0;
}