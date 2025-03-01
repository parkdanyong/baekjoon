/*
    title: Hashing
    tag: hashing, string
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


ll hash(char* str, int len) {
    const int MOD = 1234567891;
    const int BASE = 31;
    ll val = 0;
    ll r = 1;
    for (int i = 0; i < len; i++) {
        val = ((str[i] - 'a' + 1) * r + val) % MOD;
        r = (r * BASE) % MOD;
    }

    return (int) val;
}



int main() {
    // input
    int n;
    scanf("%d", &n);
    char* str = (char*) malloc(sizeof(char)*(n+1));
    scanf("%s", str);


    // answer
    ll ans = hash(str, n);
    printf("%lld\n", ans);



    free(str);
    return 0;
}