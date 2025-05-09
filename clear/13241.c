/*
    title: 최소공배수
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;



ll max(ll arg1, ll arg2) {
    return arg1 < arg2 ? arg1 : arg2;
}


ll min(ll arg1, ll arg2) {
    return arg1 > arg2 ? arg1 : arg2;
}


ll greatestCommonDivisor(ll arg1, ll arg2) {
    ll a = max(arg1, arg2);
    ll b = min(arg1, arg2);

    ll tmp = 0;
    while (1) {
        tmp = a % b;
        if (tmp == 0) break;
        a = b;
        b = tmp;
    }

    return b;
}


ll leastCommonMultiple(ll arg1, ll arg2, ll gcd)  {
    return arg1 * arg2 / gcd;
}



int main() {
    // input
    ll v1, v2;
    scanf("%lld %lld", &v1, &v2);


    // answer
    ll ans = greatestCommonDivisor(v1, v2);
    ans = leastCommonMultiple(v1, v2, ans);
    printf("%lld\n", ans);


    return 0;
}