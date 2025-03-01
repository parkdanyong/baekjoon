/*
    title: 알람 시계
    tag: math
*/


#include <stdio.h>



int main() {
    // input
    int h, m;
    scanf("%d %d", &h, &m);


    // answer
    if (45 <= m) m -= 45;
    else {
        m += 15;
        if (h == 0) h = 23;
        else h -= 1;
    }
    printf("%d %d\n", h, m);


    return 0;
}