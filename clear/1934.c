/*
    title: 최소공배수
    tag: 
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
    int T;
    scanf("%d", &T);


    // answer
    int ans = 0;
    int v1, v2;
    for (int t = 0; t < T; t++) {
        scanf("%d %d", &v1, &v2);
        ans = greatestCommonDivisor(v1, v2);
        ans = leastCommonMultiple(v1, v2, ans);
        printf("%d\n", ans);
    }


    return 0;
}