/*
    title: ??!
    tag: string
*/



#include <stdio.h>
#include <string.h>



int main() {
    // input
    char str[100];
    scanf("%s", str);


    // init
    int len = strlen(str);
    if (str[len - 2] == '\n') str[len - 2] = '\0';


    // answer
    printf("%s??!\n", str);


    return 0;
}