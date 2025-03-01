/*
    title: LCS
    tag: dp, string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LENGTH 1010


int max(int a, int b) {
    return a > b ? a : b;
}


int LCS(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int* arr = (int*) calloc((len1+1)*(len2+1), sizeof(int));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) arr[(len2+1)*i + j] = arr[(len2+1)*(i-1) + (j-1)] + 1;
            else arr[(len2+1)*i + j] = max(arr[(len2+1)*(i-1) + j], arr[(len2+1)*i + (j-1)]);
        }
    }

    // for (int i = 0; i <= len1; i++) {
    //     for (int j = 0; j <= len2; j++) {
    //         printf("%d ", arr[(len2+1)*i + j]);
    //     }
    //     printf("\n");
    // }

    int result = arr[(len2+1)*len1 + len2];
    free(arr);
    return result;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str1 = (char*) malloc(sizeof(char)*LENGTH);
    // char* str2 = (char*) malloc(sizeof(char)*LENGTH);
    // fscanf(file, "%s", str1);
    // fscanf(file, "%s", str2);
    // fclose(file);


    // input
    char* str1 = (char*) malloc(sizeof(char)*LENGTH);
    char* str2 = (char*) malloc(sizeof(char)*LENGTH);
    scanf("%s", str1);
    scanf("%s", str2);

    
    // answer
    int ans = LCS(str1, str2);
    printf("%d\n", ans);


    free(str1);
    free(str2);
    return 0;
}