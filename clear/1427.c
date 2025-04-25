/*
    title: 소트인사이드
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 20

char* arr;


int compare(const void* arg1, const void* arg2) {
    int a = (*(char*) arg1) - '0';
    int b = (*(char*) arg2) - '0';
    return b - a;
}


int main() {
    // input
    arr = (char*) malloc(sizeof(char)*MAX_SIZE);
    scanf("%s", arr);


    // answer
    int len = strlen(arr);
    qsort(arr, len, sizeof(char), compare);
    printf("%s\n", arr);


    free(arr);
    return 0;
}