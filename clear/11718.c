/*
    title: 그대로 출력하기
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*110);
    // int len;
    // while (1) {
    //     if (fgets(str, 110, file) == NULL) break;
    //     len = strlen(str);
    //     if (str[len-1] == '\n') str[len-1] = '\0';
    //     printf("%s\n", str);
    // }
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*110);
    int len;
    while (1) {
        if (fgets(str, 110, stdin) == NULL) break;
        len = strlen(str);
        if (str[len-1] == '\n') str[len-1] = '\0';
        printf("%s\n", str);
    }


    free(str);
    return 0;
}