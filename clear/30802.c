/*
    title: 웰컴 키트
    tag: math, implement

*/



#include <stdio.h>



int main() {
    // input
    int n, t, p;
    int T_shirt_size[6];
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        scanf("%d ", &T_shirt_size[i]);
    }
    scanf("%d %d", &t, &p);


    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += (int) (T_shirt_size[i] / t);
        if (T_shirt_size[i] % t != 0) sum++;
    }
    

    // answer
    printf("%d\n", sum);
    printf("%d %d\n", n / p, n % p);
    

    return 0;
}