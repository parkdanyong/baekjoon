/*
    title: 크로아티아 알파벳
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_MAX_LEN 100



int main() {
    char* str = (char*) malloc(sizeof(char)*(STRING_MAX_LEN+1));
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] == 'c') {
            if (i+1 < len && (str[i+1] == '=') || (str[i+1] == '-')) i += 1;
        }
        else if (str[i] == 'd') {
            if (i+1 < len && str[i+1] == 'z') {
                if (i+2 < len && str[i+2] == '=') i += 2;
            }
            else if (i+1 < len && str[i+1] == '-') i += 1;
        }
        else if (str[i] == 'l' || str[i] == 'n') {
            if (i+1 < len && str[i+1] == 'j') i += 1;
        }
        else if (str[i] == 's' || str[i] == 'z') {
            if (i+1 < len && str[i+1] == '=') i += 1;
        }
        ans += 1;
    }
    printf("%d\n", ans);


    free(str);
    return 0;
}