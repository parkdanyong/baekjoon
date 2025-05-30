/*
    title: 붙인드롬
    tag: 


    이거 예를들어 N=6일 때, 6자리 팰린드롬을 101000부터 시작해서 가장 큰 수까지 brute-force로 M에 나눠지나 확인하면 풀릴듯.
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define MAX_STR_LEN 100


typedef long long ll;


int N, M, half, ans;
char str[MAX_STR_LEN];


void solve() {
    

}



int main() {
    // input
    scanf("%d %d", &N, &M);
    half = N / 2;
    ans = 0;
    if (N % 2 == 0) solve();
    printf("%d\n", ans);


    return 0;
}