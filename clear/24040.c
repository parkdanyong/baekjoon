/*
    title: 예쁜 케이크
    tag: 정수론
*/



#include <stdio.h>
#include <stdlib.h>



typedef long long ll;


void solve(ll N) {
    if (N % 9 == 0) printf("TAK\n");
    else if (N % 3 == 2) printf("TAK\n");
    else printf("NIE\n");
}


int main() {
    int T;
    scanf("%d", &T);
    ll N;
    for (int t = 0; t < T; t++) {
        scanf("%lld", &N);
        solve(N);
    }
    

    return 0;
}