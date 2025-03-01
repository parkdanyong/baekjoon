/*
    title: 1로 만들기
    tag: dp


    Simple instance.
    Let's say the function ans(n) return the min number of operations.
    We can simply define the expression like "ans[n] = ans[n-1] + 1" on this problem.

    If n is 5.
    ans(5) = ans(4) + 1
    ans(4) = ans(3) + 1
    ans(3) = ans(2) + 1
    ans(2) = ans(1) + 1
    ans(1) = 0

    When n is 1, the min value is clearly 0.
    We can find min value of 2. Divide by 2 or subtract 1.
    So, ans(2) return 0 + 1.

    ans(3) = ans(2) + 1
    At this point, ans(2) is 1, so ans(3) looks 2.
    But 3 is divisible by 3. so ans(3) is 1.

    We need to compare three cases.
    The base case is ans(n-1) + 1.
    Another case is ans(n/3) + 1.
    The other case is ans(n/2) + 1.
    The min value of the three cases is the answer.

    The final define is as follow
    ans(n) = min(ans(n-1)+1, ans(n/3)+1, ans(n/2)+1)
*/



#include <stdio.h>
#include <stdlib.h>


int dp(int n, int* ans) {
    if (ans[n] != -1) return ans[n];

    ans[n] = dp(n-1, ans) + 1;
    int cmp = 0;
    if (n % 3 == 0) {
        cmp = dp(n / 3, ans) + 1;
        if (cmp < ans[n]) ans[n] = cmp;
    }
    if (n % 2 == 0) {
        cmp = dp(n / 2, ans) + 1;
        if (cmp < ans[n]) ans[n] = cmp;
    }

    return ans[n];
}


int main() {
    // input
    int n;
    scanf("%d", &n);
    

    // answer
    int* ans = (int*) malloc(sizeof(int)*(n + 1));
    for (int i = 0; i < n + 1; i++) {
        ans[i] = -1;
    }
    ans[1] = 0; // 
    printf("%d\n", dp(n, ans));
    

    free(ans);
    return 0;
}