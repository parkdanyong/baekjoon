/*
    title: 사탕 배달
    tag: dp, greedy algorithm
*/


#include <stdio.h>
#include <stdlib.h>



int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    int bag_5 = n / 5;
    int ans = -1;
    for (int i = bag_5; i >= 0; i--) {
        if ((n - i * 5) % 3 == 0) {
            ans = (n - i * 5) / 3 + i;
            break;
        }
    }
    printf("%d\n", ans);


    return 0;
}