/*
    title: 모음의 개수
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // input
    char str[500];
    int ans = 0;
    int len;
    while (1) {
        gets(str);
        if (str[0] == '#') break;

        len = strlen(str);
        ans = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ans += 1;
            else if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') ans += 1;
        }
        printf("%d\n", ans);
    }



    return 0;
}