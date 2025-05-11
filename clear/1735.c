/*
    title: 분수 합
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))


typedef long long ll;



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


ll main() {
    // input
    ll a, b, c, d;
    scanf("%lld %lld", &a, &b);
    scanf("%lld %lld", &c, &d);


    // answer
    ll numerator, denominator;
    denominator = greatestCommonDivisor(b, d);
    denominator = leastCommonMultiple(b, d, denominator);
    numerator = a * denominator / b + c * denominator / d;
    ll gcd = greatestCommonDivisor(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
    printf("%lld %lld\n", numerator, denominator);


    return 0;
}