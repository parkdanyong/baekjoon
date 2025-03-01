/*
    title: 부녀회장이 될테야
    tag: math, dp
*/



#include <stdio.h>
#include <stdlib.h>


#define RESIDENT 210

typedef long long ll;


ll* arr;


ll dp(int floor, int num) {
    if (floor == 0) return num + 1;
    else if (arr[14 * floor + num] != 0) return arr[14 * floor + num];

    ll val = 0;
    for (int i = 0; i <= num; i++) {
        val += dp(floor-1, i);
    }
    arr[14 * floor + num] = val;
    return val;
}



int main() {
    // input
    int T;
    scanf("%d", &T);
    arr = (ll*) calloc(RESIDENT, sizeof(ll));
    int k, n;
    ll ans = 0;
    for (int i = 0; i < T; i++) {
        scanf("%d", &k);
        scanf("%d", &n);
        ans = dp(k, n-1);
        printf("%lld\n", ans);
    }


    free(arr);
    return 0;
}