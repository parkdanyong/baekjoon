/*
    title: 약수 구하기
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


int N, K;


int main() {
    // input
    scanf("%d %d", &N, &K);


    // answer
    int cnt = 0;
    int ans = 1;
    while (1) {
        if (N % ans == 0) cnt += 1;
        if (cnt == K || ans > N) break;
        ans += 1;
    }
    if (cnt < K) printf("0\n");
    else printf("%d\n", ans);


    return 0;
}