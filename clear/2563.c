/*
    title: 색종이
    tag: array, implement
*/



#include <stdio.h>
#include <stdlib.h>


#define PAPER_SIZE 10000
#define PAPER_LEN 100


int N;
int* arr;


void attach(int v1, int v2) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[PAPER_LEN*(i + v1) + (j + v2)] = 1;
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // arr = (int*) calloc(PAPER_SIZE, sizeof(int));
    // int v1, v2;
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     attach(v2, v1);   
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    arr = (int*) calloc(PAPER_SIZE, sizeof(int));
    int v1, v2;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &v1, &v2);
        attach(v2, v1);   
    }


    // answer
    int ans = 0;
    for (int i = 0; i < PAPER_SIZE; i++) {
        ans += arr[i];
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}