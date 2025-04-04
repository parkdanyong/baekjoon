/*
    title: 삼각형 외우기
    tag: 
*/



#include <stdio.h>



int main() {
    // input
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    
    // answer
    if (a == 60 && b == 60 && c == 60) printf("Equilateral\n");
    else if (a + b + c == 180) {
        if (a == b || a == c || b == c) printf("Isosceles\n");
        else printf("Scalene\n");
    }
    else printf("Error\n");
    
    
    return 0;
}