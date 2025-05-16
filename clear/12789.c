/*
    title: 도키도키 간식드리미
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int N;
int* arr;


bool lineUp() {
    int* stack = (int*) malloc(sizeof(int)*N);
    int top = -1;
    int curNum = 1;
    int index = 0;
    while (curNum <= N) {
        if (arr[index] == curNum) {
            index += 1;
            curNum += 1;
        }
        else if (top >= 0 && stack[top] == curNum) {
            top -= 1;
            curNum += 1;
        }
        else if (index < N) stack[++top] = arr[index++];
        else {
            free(stack);
            return false;
        }
        
    }
    free(stack);
    return true;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // arr = (int*) malloc(sizeof(int)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    arr = (int*) malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int ans = lineUp();
    if (ans) printf("Nice\n");
    else printf("Sad\n");


    free(arr);
    return 0;
}