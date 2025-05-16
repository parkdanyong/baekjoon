/*
    title: 창문 닫기
    tag: 


    창문이 열려있으려면 약수의 개수가 홀수
    약수의 개수가 홀수이려면, 어떤 수의 제곱수
    제곱수는 전체 창문 개수의 루트 수와 같다.
    
*/



#include <stdio.h>
#include <math.h>


typedef long long ll;


ll N;


int main() {
    // input
    scanf("%lld", &N);
    printf("%lld\n", (ll) sqrt((double) N));


    return 0;
}