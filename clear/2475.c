#include <stdio.h>
#include <math.h>


int main() {
    // input
    int n = 0;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        ans += pow(n, 2);
    }
    
    
    // answer
    ans %= 10;
    printf("%d\n", ans);
    

    return 0;
}