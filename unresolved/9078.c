/*
    title: 정렬
    tag: 

    수열 패리티
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_ARR_SIZE 200


int T, N;
int* arr;


int solve() {

}



int main() {
    FILE* file = fopen("inputFile.txt", "r");
    fscanf(file, "%d", &T);
    arr = (int*) malloc(sizeof(int)*MAX_ARR_SIZE);
    for (int t = 0; t < T; t++) {
        // input
        fscanf(file, "%d", &N);
        for (int i = 0; i < N; i++) {
            fscanf(file, "%d", &arr[i]);
        }

        // answer
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
    fclose(file);


    free(arr);
    return 0;
}