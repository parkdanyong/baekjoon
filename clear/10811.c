/*
    title: 바구니 뒤집기
    tag: implement
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, m;
    // fscanf(file, "%d %d", &n, &m);
    // int* arr = (int*) malloc(sizeof(int)*(n+1));
    // for (int i = 0; i <= n; i++) {
    //     arr[i] =i;
    // }
    // int v1, v2, c, tmp;
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     c = (v2 - v1) / 2;
    //     for (int j = 0; j <= c; j++) {
    //         tmp = arr[v1+j];
    //         arr[v1+j] = arr[v2-j];
    //         arr[v2-j] = tmp;
    //     }
    // }
    // fclose(file);


    // input
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = (int*) malloc(sizeof(int)*(n+1));
    for (int i = 0; i <= n; i++) {
        arr[i] =i;
    }
    int v1, v2, c, tmp;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        c = (v2 - v1) / 2;
        for (int j = 0; j <= c; j++) {
            tmp = arr[v1+j];
            arr[v1+j] = arr[v2-j];
            arr[v2-j] = tmp;
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