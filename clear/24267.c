/*
    title: 알고리즘 수업 - 알고리즘의 수행 시간 6
    tag: 
*/



#include <stdio.h>


typedef long long ll;


int main() {
    // input
    ll n;
    scanf("%lld", &n);
    
        
    // answer
    ll ans = 0;
    for (ll i = n-2; i >= 1; i--) {
        ans += i * (n - (i+1));
    }
    printf("%lld\n3\n", ans);
        
    
    return 0;
}