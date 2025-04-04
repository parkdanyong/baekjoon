/*
    title: Caesar Cipher
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int N, L;
    // fscanf(file, "%d %d", &N, &L);
    // char* str = (char*) malloc(sizeof(char)*(L+1));
    // fgetc(file);
    // fgets(str, L+1, file);
    // for (int i = 0; i < L; i++) {
    //     if ('A' <= str[i] && str[i] <= 'Z') printf("%c", (str[i] - 'A' + N) % 26 + 'A');
    //     else if ('a' <= str[i] && str[i] <= 'z') printf("%c", (str[i] - 'a' + N) % 26 + 'a');
    //     else printf("%c", str[i]);
    // }
    // fclose(file);


    // input
    int N, L;
    scanf("%d %d", &N, &L);
    char* str = (char*) malloc(sizeof(char)*(L+1));
    fgetc(stdin);
    fgets(str, L+1, stdin);
    for (int i = 0; i < L; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') printf("%c", (str[i] - 'A' + N) % 26 + 'A');
        else if ('a' <= str[i] && str[i] <= 'z') printf("%c", (str[i] - 'a' + N) % 26 + 'a');
        else printf("%c", str[i]);
    }



    free(str);
    return 0;
}