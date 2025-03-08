/*
    title: 다이얼
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*20);
    // fscanf(file, "%s", str);
    // int len = strlen(str);
    // int c;
    // int ans = 0;
    // for (int i = 0; i < len; i++) {
    //     c = str[i] - 'A';
    //     if (c < 3) ans += 3;
    //     else if (c < 6) ans += 4;
    //     else if (c < 9) ans += 5;
    //     else if (c < 12) ans += 6;
    //     else if (c < 15) ans += 7;
    //     else if (c < 19) ans += 8;
    //     else if (c < 22) ans += 9;
    //     else ans += 10;
    // }  
    // printf("%d\n", ans);
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*20);
    scanf("%s", str);
    int len = strlen(str);
    int c;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        c = str[i] - 'A';
        if (c < 3) ans += 3;
        else if (c < 6) ans += 4;
        else if (c < 9) ans += 5;
        else if (c < 12) ans += 6;
        else if (c < 15) ans += 7;
        else if (c < 19) ans += 8;
        else if (c < 22) ans += 9;
        else ans += 10;
    }  
    printf("%d\n", ans);



    free(str);
    return 0;
}