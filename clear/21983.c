/*
    title: Basalt Breakdown
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double N;



int main() {
    // input
    scanf("%lf", &N);


    // answer
    double ans = sqrt((2 * N) / (3 * sqrt(3)));
    ans *= 6;
    printf("%.8lf\n", ans);


    return 0;
}