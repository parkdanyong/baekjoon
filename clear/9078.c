/*
    title: 정렬
    tag: 

    역전의 수 패리티
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_ARR_SIZE 200


int T, N;
int* arr;


int solve() {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1 ; j < N; j++) {
            if (arr[i] > arr[j]) count += 1;
        }
    }
    return count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &T);
    // arr = (int*) malloc(sizeof(int)*MAX_ARR_SIZE);
    // for (int t = 0; t < T; t++) {
    //     // input
    //     fscanf(file, "%d", &N);
    //     for (int i = 0; i < N; i++) {
    //         fscanf(file, "%d", &arr[i]);
    //     }

    //     // answer
    //     if (solve() % 2 == 0) printf("YES\n");
    //     else printf("NO\n");
    // }
    // fclose(file);


    // input
    scanf("%d", &T);
    arr = (int*) malloc(sizeof(int)*MAX_ARR_SIZE);
    for (int t = 0; t < T; t++) {
        // input
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        // answer
        if (solve() % 2 == 0) printf("YES\n");
        else printf("NO\n");
    }
    

    free(arr);
    return 0;
}