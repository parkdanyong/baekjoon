/*
    title: 이항 계수 1
    tag: math, implement, combinatorics

*/



#include <stdio.h>
#include <stdlib.h>


int binomialCoefficient(int n, int k) {
    if (n - k <= (int) n / 2) k = n - k;

    int result = 1;
    int div = 1;
    for (int i = 1; i <= k; i++) {
        result *= n--;
        div *= i;
    }
    
    return result / div;
}



int main() {
    // input
    int n, k;
    scanf("%d %d", &n, &k);


    // answer
    int ans = 0;
    ans = binomialCoefficient(n, k);
    printf("%d\n", ans);


    return 0;
}