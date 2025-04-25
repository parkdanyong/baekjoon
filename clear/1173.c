/*
    title: 운동
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define max(X, Y) (X) > (Y) ? (X) : (Y)



int main() {
    // input
    int N, m, M, T, R;
    scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);


    // answer
    int ans = 0;
    int goal = 0;
    int cur = m;
    while (1) {
        if (goal >= N) break;
        if (M - m < T) {
            ans = -1;
            break;
        }

        if (cur + T <= M) {
            cur += T;
            goal += 1;
        }
        else cur = max(cur-R, m);
        ans += 1;
    }
    printf("%d\n", ans);


    return 0;
}