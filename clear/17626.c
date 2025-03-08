/*
    title: Four Squares
    tag: dp, brute force



    
    dp(12) = 3 = dp(8) + dp(4)
    dp(11) = 3
    dp(10) = 2
    dp(9) = 1
    dp(8) = 2 = dp(4) + dp(4)
    dp(7) = 4
    dp(6) = 3
    dp(5) = 2   
    dp(4) = 1
    dp(3) = 3
    dp(2) = 2
    dp(1) = 1
    dp(0) = 0

*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


// int dp(int n) {
//     if (n == 0) return 0;
//     else if (arr[n] != 0) return arr[n];


//     int val;
//     for (val = n; val > 0; val--) {
//         if (n >= pow(val,2)) break;
//     }

//     arr[n] = dp(n-1);
//     int cmp = dp(n - (int) pow(val-1,2));
//     arr[n] = min(arr[n], cmp) + 1;

//     return arr[n];
// }



int main() {
    // input
    int n;
    scanf("%d", &n);


    // init
    arr = (int*) calloc(n + 1, sizeof(int));
    arr[1] = 1;


    // answer
    int minVal = 0;
    int j = 0;
    for (int i = 2; i <= n; i++) {
        minVal = pow(10, 5);
        j = 1;

        while (pow(j,2) <= i) {
            minVal = min(minVal, arr[i - (int) pow(j, 2)]); // 이게 왜 최소값을 보장함?
            j += 1;
        }
        arr[i] = minVal += 1;
    }
    // for (int i = 0; i <= n; i++) {
    //     printf("n: %d ans: %d\n", i, arr[i]);
    // }
    printf("%d\n", arr[n]);


    free(arr);
    return 0;
}