/*
    title: 알파벳 찾기
    tag: string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    // input
    char* str =(char*) malloc(sizeof(char)*110);
    scanf("%s", str);


    // init
    int* ans = (int*) malloc(sizeof(int)*26);
    for (int i = 0; i < 26; i++) {
        ans[i] = -1;
    }
    int len = strlen(str);


    // answer
    int pos;
    for (int i = 0; i < len; i++) {
        pos = str[i] - 'a';
        if (ans[pos] == -1) ans[pos] = i;
    }
    for (int i = 0; i < 26; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");




    free(str);
    free(ans);
    return 0;
}