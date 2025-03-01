/*
    title: IOIOI
    tag: string, sliding window, KMP algorithm
    
    
    Subtask 1
    Sliding-Window algorithm

    Subtask 2
    KMP algorithm

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void computeLPSArray(char* pattern, int n, int* lps) {
    int len = 0; 
    lps[0] = 0; 
    int i = 1; 

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int KMP(char* str, char* pattern) {
    int n = strlen(str);
    int m = strlen(pattern);

    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0;  
    int j = 0;  
    int count = 0;  

    while (i < n) {
        if (pattern[j] == str[i]) {
            i++;
            j++;
        }

        if (j == m) {  
            count++;  
            j = lps[j - 1];  
        }
        else if (i < n && pattern[j] != str[i]) {  
            if (j != 0) {
                j = lps[j - 1];  
            }
            else {
                i++;  
            }
        }
    }

    return count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int len;
    // fscanf(file, "%d", &len);
    // char* str = (char*) malloc(sizeof(char)*1000001);
    // fscanf(file, "%s", str);
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    int len;
    scanf("%d", &len);
    char* str = (char*) malloc(sizeof(char)*1000001);
    scanf("%s", str);


    // answer Sliding-Window
    // int count = 0;
    // int ans = 0;
    // for (int i = 0; i <= len - (n*2 + 1); i++) {
    //     for (int j = 0; j < n*2 + 1; j++) {
    //         if (count % 2 == 0) { // I
    //             if (str[i + j] == 'I') count += 1;
    //             else break;
    //         }
    //         else { // O
    //             if (str[i + j] == 'O') count += 1;
    //             else break;
    //         }
    //     }
    //     if (count == n*2 + 1) ans += 1;
    //     count = 0;
    // }
    // printf("%d\n", ans);


    // init
    char* pattern = (char*) malloc(sizeof(char)*(n+1)*2);
    pattern[n*2+1] = '\0';
    for (int i = 0; i <= n*2; i++) {
        if (i % 2 == 0) pattern[i] = 'I';
        else pattern[i] = 'O';
    } 


    // answer KMP
    int ans = KMP(str, pattern);
    printf("%d\n", ans);


    free(str);
    return 0;
}