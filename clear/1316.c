/*
    title: 그룹 단어 체커
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STIRNG_MAX_LEN 100


int N;
int* arr;
char* str;



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // arr = (int*) calloc(26, sizeof(int));
    // str = (char*) malloc(sizeof(char)*(STIRNG_MAX_LEN+1));
    // int ans = 0;
    // int len = 0;
    // int flag = 1;
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%s", str);
    //     len = strlen(str);
    //     flag = 1;
    //     for (int j = 0; j < len; j++) {
    //         if (arr[str[j]-97] != 0) {
    //             if (0 <= j-1 && str[j-1] != str[j]) {
    //                 flag = 0;
    //                 break; 
    //             }
    //         }
    //         arr[str[j]-97] += 1;
    //     }
    //     if (flag) ans += 1;
    //     memset(arr, 0, sizeof(int)*26);
    // }
    // printf("%d\n", ans);
    // fclose(file);


    // input
    scanf("%d", &N);
    arr = (int*) calloc(26, sizeof(int));
    str = (char*) malloc(sizeof(char)*(STIRNG_MAX_LEN+1));
    int ans = 0;
    int len = 0;
    int flag = 1;
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        len = strlen(str);
        flag = 1;
        for (int j = 0; j < len; j++) {
            if (arr[str[j]-97] != 0) {
                if (0 <= j-1 && str[j-1] != str[j]) {
                    flag = 0;
                    break; 
                }
            }
            arr[str[j]-97] += 1;
        }
        if (flag) ans += 1;
        memset(arr, 0, sizeof(int)*26);
    }
    printf("%d\n", ans);


    free(arr);
    free(str);
    return 0;
}