/*
    title: 나머지
    tag: math
*/


#include <stdio.h>
#include <stdlib.h>


int main() {
    // input
    char* arr = (char*) calloc(42, sizeof(char));
    int n;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &n);
        arr[(int) n % 42] = 'B';
    }


    // ans
    int ans = 0;
    for (int i = 0; i < 42; i++) {
        if (arr[i] == 'B') ans += 1;
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}