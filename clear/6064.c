/*
    title: 카잉 달력
    tag: math, brute force, 
*/




#include <stdio.h>
#include <stdlib.h>


int m, n, x, y;


int max(int arg1, int arg2) {
    return arg1 < arg2 ? arg1 : arg2;
}


int min(int arg1, int arg2) {
    return arg1 > arg2 ? arg1 : arg2;
}


int greatestCommonDivisor(int arg1, int arg2) { // 최대공약수
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


int leastCommonMultiple(int arg1, int arg2, int gcd) { // 최소공배수
    return arg1 * arg2 / gcd;
}


int ans(int lcm) {
    for (int i = x; i <= lcm; i += m) {
        if ((i - y) % n == 0) return i;
    }
    return -1;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int t;
    // fscanf(file, "%d", &t);
    // int tmp = 0;
    // for (int i = 0; i < t; i++) {
    //     fscanf(file, "%d %d %d %d", &m, &n, &x, &y);
    //     tmp = greatestCommonDivisor(m, n);
    //     tmp = leastCommonMultiple(m, n, tmp);
    //     printf("%d\n", ans(tmp));
    // }
    // fclose(file);


    // input
    int t;
    scanf("%d", &t);


    // answer
    int tmp = 0;
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d %d", &m, &n, &x, &y);
        tmp = greatestCommonDivisor(m, n);
        tmp = leastCommonMultiple(m, n, tmp);
        printf("%d\n", ans(tmp));
    }


    return 0;
}