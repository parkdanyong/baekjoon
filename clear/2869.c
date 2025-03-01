/*
    title: 달팽이는 올라가고 싶다
    tag: math
*/



#include <stdio.h>



int main() {
    // input
    int A, B, V;
    scanf("%d %d %d", &A, &B, &V);


    // answer
    int ans = (V - A) / (A - B) + 1;
    if ((V - A) % (A - B) != 0) ans += 1; 
    printf("%d\n", ans);


    return 0;
}