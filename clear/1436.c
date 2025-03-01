/*
    title: 영화감독 숌
    tag: brute force
*/



#include <stdio.h>


int series(int num) {
    int count = 0;
    while (num != 0 && count != 3) {
        if (num % 10 == 6) count += 1;
        else count = 0;
        num /= 10;
    }

    if (count == 3) return 1;
    else return 0;
}



int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    int ans = 666;
    int cmp = 1;
    while (cmp != n) {
        ans += 1;
        if (series(ans)) cmp += 1;
    }
    printf("%d\n", ans);


    return 0;
}