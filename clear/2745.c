/*
    title: 진법 변환
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long ll;

char N[50];
ll B;


int transfrom(char c) {
    if (c < 65) return c - '0';
    else return (int) c - 'A' + 10;
}


int main() {
    // input
    scanf("%s %d", N, &B);


    // answer
    int len = strlen(N);
    ll tmp = 1;
    ll ans = 0; 
    for (int i = len-1; i >= 0; i--) {
        ans += (tmp * (ll) transfrom(N[i]));
        tmp *= B;
    }
    printf("%lld\n", ans);


    return 0;
}