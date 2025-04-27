/*
    title: 피시방 알바
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 101


int n;
int* arr;



int main() {
    // input
    scanf("%d", &n);
    arr = (int*) calloc(MAX_SIZE, sizeof(int));
    int pos;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos);
        if (arr[pos] == 1) ans += 1;
        else arr[pos] = 1;
    }
    printf("%d\n", ans);
        
    
    free(arr);
    return 0;
}