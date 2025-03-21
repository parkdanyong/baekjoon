/*
    title: 진법 변환 2
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef long long ll;


ll N;
char ans[50];
ll B;


char transfrom(ll c) {
    if (c < 10) return (char) c + '0';
    else return (char) c - 10 + 'A';
}


int main() {
    // input
    scanf("%lld %lld", &N, &B);


    // answer
    int len = 0;
    while (N > 0) {
        ans[len++] = transfrom(N % B);
        N /= B;
    }
    for (int i = len-1; i >= 0; i--) {
        printf("%c", ans[i]);
    }
    printf("\n", ans);


    return 0;
}