/*
    title: 최대공약수와 최소공배수
    tag: math, Euclidean algorithm
*/




#include <stdio.h>
#include <stdlib.h>


int max(int arg1, int arg2) {
    return arg1 < arg2 ? arg1 : arg2;
}


int min(int arg1, int arg2) {
    return arg1 > arg2 ? arg1 : arg2;
}


int greatestCommonDivisor(int arg1, int arg2) {
    int a = max(arg1, arg2);
    int b = min(arg1, arg2);

    int tmp = 0;
    while (1) {
        tmp = a % b;
        if (tmp == 0) break;
        a = b;
        b = tmp;
    }

    return b;
}


int leastCommonMultiple(int arg1, int arg2, int gcd)  {
    return arg1 * arg2 / gcd;
}



int main() {
    // input
    int a, b;
    scanf("%d %d", &a, &b);
    

    // answer
    int ans = 0;
    ans = greatestCommonDivisor(a, b);
    printf("%d\n", ans);
    ans = leastCommonMultiple(a, b, ans);
    printf("%d\n", ans);


    return 0;
}