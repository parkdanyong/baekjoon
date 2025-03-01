/*
    title: 분해합
    tag: brute force
*/



#include <stdio.h>


int solve(int val) {
    int result = val;
    for (int i = 1; i <= 1000000; i *= 10) {
        result += val / i % 10;
    }
    return result;
}
 

int main() {
    // input
    int n;
    scanf("%d", &n);


    // answer
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (solve(i) == n) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);


    return 0;
}