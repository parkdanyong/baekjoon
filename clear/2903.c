/*
    title: 중앙 이동 알고리즘
    tag: math
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef long long ll;


ll N;



int main() {
    // input
    scanf("%lld", &N);


    // answer
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans *= 2;
    }
    ans = (ans + 1) * (ans + 1);
    printf("%lld\n", ans);


    return 0;
}