/*
    title: 나누기
    tag: 
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
    ll tmp = n % f;
    if ((n - tmp) % 100 <= (n + (f - tmp)) % 100) printf("%02lld\n", (n - tmp) % 100);
    else printf("%02lld\n", (n + (f - tmp)) % 100);
    printf("%02lld\n", (n - tmp) % 100);
    printf("%02lld\n", (n + (f - tmp)) % 100);

    return 0;
}