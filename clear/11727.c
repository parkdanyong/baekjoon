/*
    title: 2×n 타일링 2
    tag: dp


    dp(n) = dp(n-1) + 2*dp(n-2)
    dp(8) = dp(7) + 2*dp(6) =  171 
    dp(7) = dp(6) + 2*dp(5) = 85
    dp(6) = dp(5) + 2*dp(4) = 43
    dp(5) = dp(4) + 2*dp(3) = 21
    dp(4) = dp(3) + 2*dp(2) = 11
    dp(3) = dp(2) + 2*dp(1) = 5
    dp(2) = 3
    dp(1) = 1
    
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


int main() {
    // input
    int n;
    scanf("%d", &n);


    // init
    ll* arr = (ll*) malloc(sizeof(ll)*(n + 1));
    arr[1] = 1;
    arr[2] = 3;


    // answer
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
    }
    printf("%d\n", arr[n]);



    free(arr);
    return 0;
}