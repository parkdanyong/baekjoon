/*
    title: 팰린드롬 분할
    tag: 

    
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_ARRAY_LEN 2500



char* arr;
int len, size;
int* p_matrix;


void palindrome() { 
    for (int i = 0; i < size; i++) {
        p_matrix[i] = 1;
    }

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[i] == arr[j]) p_matrix[(len+1)*i + j] = p_matrix[(len+1)*(i-1) + (j+1)];
            else p_matrix[(len+1)*i + j] = 0;
        }
    }
}



int main() {
    // input
    arr = (char*) malloc(sizeof(char)*(MAX_ARRAY_LEN+1));
    scanf("%s", arr);
    len = strlen(arr);
    size = (len+1) * (len+1);


    // init
    p_matrix = (int*) malloc(sizeof(int)*size);


    // answer
    palindrome();



    free(arr);
    free(p_matrix);
    return 0;
}