/*
    title: 나누기
    tag: brute force
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;



int main() {
    // input
    ll n, f;
    scanf("%lld", &n);
    scanf("%lld", &f);


    // answer
    ll ans = 0;
    ll tmp = n - (n % 100);
    for (; ans < 100; ans++) {
        if ((tmp + ans) % f == 0) break;
    }
    printf("%02lld\n", ans);


    return 0;
}