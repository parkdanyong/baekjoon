/*
    title: 단어 공부
    tag: string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STRING_MAX_LEN 1000000


int main() {
    char* str = (char*) malloc(sizeof(char)*(STRING_MAX_LEN + 1));
    int* arr = (int*) calloc(26, sizeof(int));
    scanf("%s", str);
    int len = strlen(str);
    char c;
    for (int i = 0; i < len; i++) {
        c = str[i];
        if (c < 97) c -= 65;
        else c -= 97;
        arr[c] += 1;
    }


    // answer
    int cmp = -1;
    int ans = 0;
    for (int i = 1; i < 26; i++) {
        if (arr[ans] == arr[i]) cmp = i;
        else if (arr[ans] < arr[i]) ans = i;
    }
    if (arr[ans] == arr[cmp]) printf("?\n");
    else printf("%c\n", ans+65);


    free(str);
    free(arr);
    return 0;
}