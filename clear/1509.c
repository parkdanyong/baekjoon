/*
    title: 팰린드롬 분할
    tag: dp
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define INF 10000
#define MAX_ARRAY_LEN 2500



char* arr;
int len, size;
int* p_matrix;
int* dp;


void palindrome() { 
    for (int i = 0; i < size; i++) {
        p_matrix[i] = 1;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) p_matrix[(len)*i + j] = p_matrix[(len)*(i-1) + (j+1)];
            else p_matrix[(len)*i + j] = 0;
        }
    }
}


int main() {
    // input
    arr = (char*) malloc(sizeof(char)*(MAX_ARRAY_LEN+1));
    scanf("%s", arr);
    len = strlen(arr);
    size = len * len;


    // init
    p_matrix = (int*) malloc(sizeof(int)*size);
    dp = (int*) malloc(sizeof(int)*len);
    for (int i = 0; i < len; i++) {
        dp[i] = INF;
    }


    // answer
    palindrome();
    for (int i = 0; i < len; i++) {
        if (p_matrix[len*i + 0] == 1) dp[i] = 1;
        else {
            for (int j = 0; j < i; j++) {
                if (p_matrix[len*i + (i-j)] == 1) dp[i] = min(dp[i], dp[(i-j-1)]+1);
            }
        }
    }
    printf("%d\n", dp[len-1]);


    free(arr);
    free(p_matrix);
    free(dp);
    return 0;
}