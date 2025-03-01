/*
    title: OX퀴즈
    tag: implement, string
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // char* arr =  (char*) malloc(sizeof(char)*100);
    // int tmp = 0;
    // int len;
    // int ans = 0;
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%s", arr);
    //     len = strlen(arr);
    //     for (int i = 0; i <len; i++) {
    //         if (arr[i] == 'O') tmp += 1;
    //         else tmp = 0;
    //         ans += tmp;
    //     }
    //     printf("%d\n", ans);
    //     ans = 0;
    //     tmp = 0;
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);


    // init
    char* arr =  (char*) malloc(sizeof(char)*100);
    int tmp = 0;
    int len;


    // answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", arr);
        len = strlen(arr);
        for (int i = 0; i <len; i++) {
            if (arr[i] == 'O') tmp += 1;
            else tmp = 0;
            ans += tmp;
        }
        printf("%d\n", ans);
        ans = 0;
        tmp = 0;
    }




    free(arr);
    return 0;
}