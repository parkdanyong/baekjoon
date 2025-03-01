/*
    title: A → B
    tag: graph, BFS, greedy algorithm

    A * 2 (become a even number)
    A * 10 + 1 (the digit of 1 become 1)


    Solution: top-down / B -> A
    operation
        1. B / 2 (when B is even)
        2. (B - 1) / 10 (when B is odd and digit of 1 is 1)
    
    1. simple instance
        162 (even) -> op 1.
        81 (odd, digit of 1 is 1) -> op 2.
        8 (even) -> op 1.
        4 (even) -> op 1.
        2 (equal A)
        answer: 5

    2. simple instance
        42 (even) -> op 1.
        21 (odd, digit of 1 is 1) -> op 2.
        2 (less than A) 
        answer: -1

*/


#include <stdio.h>
#include <stdlib.h>


int main() {
    // input
    int A, B;
    scanf("%d %d", &A, &B);


    // answer
    int cur = B;
    int ans = 1;
    while (cur > A) {
        if (cur % 2 == 1) { 
            if (cur % 10 == 1) cur = (cur - 1) / 10;
            else break;
        }
        else cur /= 2;
        ans += 1;
    }
    if (cur == A) printf("%d\n", ans);
    else printf("-1\n");


    return 0;
}