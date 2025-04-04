/*
    title: 삼각형과 세 변
    tag: 
*/



#include <stdio.h>

int main() {
    int a, b, c;
    
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0) break;

        
        if (a + b <= c || a + c <= b || b + c <= a) {
            printf("Invalid\n");
            continue;
        }

        if (a == b && b == c) printf("Equilateral\n");
        else if (a == b || a == c || b == c) printf("Isosceles\n");
        else printf("Scalene\n");
    }
    
    return 0;
}
