/*
    title: 다음 소수
    tag: 
*/



#include <stdio.h>
#include <stdbool.h>
#include <math.h>


typedef long long ll;


ll T, N;


bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false; // 짝수는 소수가 아님

    ll i;
    ll root = (ll) sqrt(n);
    for (i = 3; i <= root; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}




int main() {
    scanf("%lld", &T);
    for (int t = 0; t < T; t++) {
        scanf("%lld", &N);
        while (!isPrime(N)) {
            N += 1;
        }
        printf("%lld\n", N);
    }


    return 0;
}