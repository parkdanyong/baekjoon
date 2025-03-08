/*
    title: 킹, 퀸, 룩, 비숍, 나이트, 폰
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>




int main() {
    // input
    int package[6] = {1, 1, 2, 2, 2, 8};
    int arr[6];
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }
    
    
    // answer
    for (int i = 0; i < 6; i++) {
        printf("%d ", package[i]-arr[i]);
    }    
    printf("\n");
    
    
    return 0;
}