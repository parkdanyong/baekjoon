/*
    title: 벌집
    tag: math


    layer: count
    1: 1
    2: 6, 2 ~ 7
    3: 12, 8 ~ 19
    4: 18, 20 ~ 37
    5: 24, 38 ~ 61

*/



#include <stdio.h>



int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    int i = 1;
    int cmp = 1;
    int ans = 1;
    while (cmp < n) {
        cmp += 6 * i++;
        ans += 1;
    }
    printf("%d\n", ans);


    return 0;
}
