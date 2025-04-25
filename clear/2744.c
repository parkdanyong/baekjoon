/*
    title: 대소문자 바꾸기
    tag: 
*/



#include <stdio.h>



int main() {
    // input
    char str[200];
    scanf("%s", str);
    int i = 0;
    while (1) {
        if (str[i] == '\0') break;


        if (str[i] < 'a') printf("%c", str[i] + 32);
        else printf("%c", str[i] - 32);
        i += 1;
    }
    
    
    return 0;
}