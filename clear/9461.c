/*
    title: 파도반 수열
    tag: math, dp


    dp(10) = 9 = dp(9) + dp(5)
    dp(9) = 7 = dp(8) + dp(4)
    dp(8) = 5 = dp(7) + dp(3)
    dp(7) = 4 = dp(6) + dp(2)
    dp(6) = 3 = dp(5) + dp(1)
    dp(5) = 2 = dp(4) + dp(0)
    dp(4) = 2 
    dp(3) = 1
    dp(2) = 1
    dp(1) = 1
    dp(0) = 0

*/




#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


ll* mem;


ll dp(int n) {
    if (n == 0) return 0;
    else if (mem[n] != 0) return mem[n];

    mem[n] = dp(n-1);
    mem[n] += dp(n-5);
    return mem[n];
}



int main() {
    // input
    int t;
    scanf("%d", &t);
    int* arr = (int*) malloc(sizeof(int)*t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    // init
    mem = (ll*) calloc(101, sizeof(ll));
    mem[0] = 0;
    mem[1] = 1;
    mem[2] = 1;
    mem[3] = 1;
    mem[4] = 2;


    // answer
    int n;
    ll ans = 0;
    for (int i = 0; i < t; i++) {
        ans = dp(arr[i]);
        printf("%lld\n", ans);
    }


    free(mem);
    return 0;
}