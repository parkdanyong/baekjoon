/*
    title: 팰린드롬수
    tag: implement, string
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isPalindrome(char* str, int len) {
    int repeat = len / 2;
    for (int i = 0; i < repeat; i++) {
        if (str[i] != str[len - 1 - i]) return 0;
    }
    return 1;
}




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*6);
    // size_t len = 0;
    // while (1) {
    //     fscanf(file, "%s", str);
    //     if (str[0] == '0') break;
    //     len = strlen(str); 
    //     if(isPalindrome(str, len)) printf("YES\n");
    //     else printf("NO\n");
    // }
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*6);
    size_t len = 0;
    while (1) {
        scanf("%s", str);
        if (str[0] == '0') break;
        len = strlen(str); 
        if(isPalindrome(str, len)) printf("yes\n");
        else printf("no\n");
    }
    


    free(str);
    return 0;
}