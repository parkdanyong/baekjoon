/*
    title: 1의 개수 세기
    tag: prefix sum, bit masking
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


ll A, B;



int main() {
    // input
    scanf("%lld %lld", &A, &B);
    A -= 1;
    

    // answer
    ll ans = 0;
    ll cmp = 1;
    ll tmp;
    while (cmp <= B) {
        tmp = (B - (cmp - 1)) / cmp + 1;
        if (tmp % 2 == 1) ans += (B - (cmp - 1)) % cmp;
        ans += tmp / 2 * cmp;
        cmp *= 2;
    }
    cmp = 1;
    while (cmp <= A) {
        tmp = (A - (cmp - 1)) / cmp + 1;
        if (tmp % 2 == 1) ans -= (A - (cmp - 1)) % cmp;
        ans -= tmp / 2 * cmp;
        cmp *= 2;
    }
    printf("%lld\n", ans);


    return 0;
}