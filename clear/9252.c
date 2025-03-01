/*
    title: LCS 2
    tag: dp, string
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STRING_LEN 1001



char* str1;
char* str2;
int len1;
int len2;


int max(int a, int b) {
    return a > b ? a : b;
}


void LCS() {
    int* arr = (int*) calloc((len1+1) * (len2+1), sizeof(int));

    int i = 0, j = 0;
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) arr[(len2+1)*i + j] = arr[(len2+1)*(i-1) + (j-1)] + 1;
            else arr[(len2+1)*i + j] = max(arr[(len2+1)*(i-1) + j], arr[(len2+1)*i + (j-1)]);
        }
    }

    int len = arr[(len2+1)*len1 + len2];
    printf("%d\n", len);
    char* lcs = (char*) malloc(sizeof(char)*(len+1));
    lcs[len] = '\0';
    i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) { 
            lcs[len - 1] = str1[i - 1];
            i--;
            j--;
            len--;
        } else if (arr[(len2+1)*(i-1) + j] > arr[(len2+1)*i + (j-1)]) i--;
        else j--;
    }
    printf("%s\n", lcs);
    free(arr);
    free(lcs);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // str1 = (char*) malloc(sizeof(int)*MAX_STRING_LEN);
    // str2 = (char*) malloc(sizeof(int)*MAX_STRING_LEN);
    // fscanf(file, "%s", str1);
    // fscanf(file, "%s", str2);
    // len1 = strlen(str1);
    // len2 = strlen(str2);
    // fclose(file);


    // input
    str1 = (char*) malloc(sizeof(int)*MAX_STRING_LEN);
    str2 = (char*) malloc(sizeof(int)*MAX_STRING_LEN);
    scanf("%s", str1);
    scanf("%s", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);


    // answer
    LCS();


    free(str1);
    free(str2);
    return 0;
}