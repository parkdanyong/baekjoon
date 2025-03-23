/*
    title: 분수찾기
    tag: math
*/



#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10000000


int N;


int main() {
    // input
    scanf("%d", &N);


    // answer
    int cmp = 1;
    int ans = 1;
    while (1) {
        if (ans + cmp > N) break;
        ans += cmp;
        cmp += 1;
    }
    ans = N - ans;
    if (cmp % 2 == 0) printf("%d/%d\n", 1+ans, cmp-ans);
    else printf("%d/%d\n", cmp-ans, 1+ans);


    return 0;
}