/*
    title: 공 넣기
    tag: implement
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, m;
    // fscanf(file, "%d %d", &n, &m);
    // int* arr = (int*) calloc(n+1, sizeof(int));
    // int start, end, num;
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d %d %d", &start, &end, &num);
    //     for (int j = start; j <= end; j++) {
    //         arr[j] = num;
    //     }
    // }
    // fclose(file);


    // input
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = (int*) calloc(n+1, sizeof(int));
    int start, end, num;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &start, &end, &num);
        for (int j = start; j <= end; j++) {
            arr[j] = num;
        }
    }


    // answer
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


    free(arr);
    return 0;
}