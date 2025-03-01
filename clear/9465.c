/*
    title: 스티커
    tag: dp


    ans[0]: max value when top row is selected
    ans[1]: max value when bottom row is selected
    ans[0][n] = max(ans[1][n-1], ans[0][n-2], ans[1][n-2]) + arr[0][n]

    
    Like the example, sometimes the value is larger when you move on without making a choice.
    
*/



#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    return a > b ? a : b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int T;
    // fscanf(file, "%d", &T);
    // int** arr = (int**) malloc(sizeof(int*)*2);
    // arr[0] = (int*) malloc(sizeof(int)*100001);
    // arr[1] = (int*) malloc(sizeof(int)*100001);
    // arr[0][0] = 0;
    // arr[1][0] = 0;
    // int** ans = (int**) malloc(sizeof(int*)*2);
    // ans[0] = (int*) malloc(sizeof(int)*100001);
    // ans[1] = (int*) malloc(sizeof(int)*100001);
    // ans[0][0] = 0;
    // ans[1][0] = 0;
    // int n;
    // for (int i = 0; i < T; i++) {
    //     fscanf(file, "%d", &n);
    //     for (int j = 0; j < 2; j++) {
    //         for (int k = 1; k <= n; k++) {
    //             fscanf(file, "%d", &arr[j][k]);
    //         }
    //     }
        

    //     int cmp;
    //     ans[0][1] = arr[0][1];
    //     ans[1][1] = arr[1][1];
    //     for (int j = 2; j <= n; j++) {
    //         cmp = max(ans[0][j-2], ans[1][j-2]);
    //         ans[0][j] = max(ans[1][j-1], cmp) + arr[0][j];
    //         ans[1][j] = max(ans[0][j-1], cmp) + arr[1][j];
    //     }

    //     printf("%d\n",max(ans[0][n], ans[1][n]));
    // }
    // fclose(file);


    // input
    int T;
    scanf("%d", &T);


    // init
    int** arr = (int**) malloc(sizeof(int*)*2);
    arr[0] = (int*) malloc(sizeof(int)*100001);
    arr[1] = (int*) malloc(sizeof(int)*100001);
    arr[0][0] = 0;
    arr[1][0] = 0;
    int** ans = (int**) malloc(sizeof(int*)*2);
    ans[0] = (int*) malloc(sizeof(int)*100001);
    ans[1] = (int*) malloc(sizeof(int)*100001);
    ans[0][0] = 0;
    ans[1][0] = 0;


    // answer
    int n;
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= n; k++) {
                scanf("%d", &arr[j][k]);
            }
        }
        
        int cmp;
        ans[0][1] = arr[0][1];
        ans[1][1] = arr[1][1];
        for (int j = 2; j <= n; j++) {
            cmp = max(ans[0][j-2], ans[1][j-2]);
            ans[0][j] = max(ans[1][j-1], cmp) + arr[0][j];
            ans[1][j] = max(ans[0][j-1], cmp) + arr[1][j];
        }
        
        printf("%d\n",max(ans[0][n], ans[1][n]));
    }



    free(arr[0]);
    free(arr[1]);
    free(arr);
    free(ans[0]);
    free(ans[1]);
    free(ans);
    return 0;
}