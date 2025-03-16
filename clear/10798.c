/*
    title: 세로읽기
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STRING_LEN 20


char** str;
int* length;


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // str = (char**) malloc(sizeof(char*)*5);
    // for (int i = 0; i < 5; i++) {
    //     str[i] = (char*) malloc(sizeof(char)*MAX_STRING_LEN);
    // }
    // length = (int*) malloc(sizeof(int)*5);
    // for (int i = 0; i < 5; i++) {
    //     fscanf(file, "%s", str[i]);
    // }
    // fclose(file);


    // input
    str = (char**) malloc(sizeof(char*)*5);
    for (int i = 0; i < 5; i++) {
        str[i] = (char*) malloc(sizeof(char)*MAX_STRING_LEN);
    }
    length = (int*) malloc(sizeof(int)*5);
    for (int i = 0; i < 5; i++) {
        scanf("%s", str[i]);
    }


    // init
    int maxLen = 0;
    for (int i = 0; i < 5; i++) {
        length[i] = strlen(str[i]);
        if (maxLen < length[i]) maxLen = length[i];
    }


    // answer
    for (int i = 0; i < maxLen; i++) {
        for (int j = 0; j < 5; j++) {
            if (i < length[j]) {
                printf("%c", str[j][i]);
            }
        }
    }


    for (int i = 0; i < 5; i++) {
        free(str[i]);
    }
    free(str);
    free(length);
    return 0;
}