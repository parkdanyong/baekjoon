/*
    title: 곱셈
    tag: math, divide and conquer



    integer max: 2^31 - 1
    long long max: 2^63 - 1

    (integer max)^2 < 2^62
    
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


ll A, B, C;


ll dp(ll b) {
    if (b == 0) return 1;
    else if (b == 1) return A % C;

    ll val;
    if (b % 2 == 0) {
        val = dp(b/2);
        return (val * val) % C;
    }
    else {
        val = dp((b-1)/2);
        return ((val * val) % C * A) % C;
    }
}



int main() {
    // input
    scanf("%lld %lld %lld", &A, &B, &C);


    // answer
    ll ans = 0;
    ans = dp(B);
    printf("%d\n", (int) ans);


    return 0;
}
