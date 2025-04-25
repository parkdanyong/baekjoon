/*
    title: 하얀 칸
    tag: 
*/



#include <stdio.h>



int main() {
    // input
    int ans = 0;
    char c;
    for (int i = 0 ; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            c = getchar();
            if ((i + j) % 2 == 0 && c == 'F') ans += 1;
        }
        c = getchar();
    }
    
    
    // answer
    printf("%d\n", ans);
    
    
    return 0;
}