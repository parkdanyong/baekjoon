/*
    title: 체스판 다시 칠하기
    tag: brute force
*/




#include <stdio.h>
#include <stdlib.h>


int min(int a, int b) {
    return a < b ? a : b;
}


int countBoard(char* arr, int m, int row, int col) {
    /*
        I check both (start with W and start with B) at the same time.
        The base is starting with W.
    */
    int start_w = 0;
    int start_b = 0;

    int rows = row + 8;
    int cols = col + 8;
    for (int i = row; i < rows; i++) {
        for (int j = col; j < cols; j++) {
            // start with W
            if (((i - row) % 2 + (j - col) % 2) % 2 == 0) { 
                if (arr[i*m + j] == 'W') start_b += 1; // start with W
                else start_w += 1; // start with B
            }
            else { 
                if (arr[i*m + j] == 'B') start_b += 1; // start with W
                else start_w += 1; // start with b
            }
        }
    }

    return min(start_w, start_b);
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, m;
    // fscanf(file, "%d %d", &n, &m);
    // char* arr = (char*) malloc(sizeof(char)*n*m);
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         fscanf(file, " %c", &arr[i*m + j]);   
    //     }
    // }
    // fclose(file);


    // input
    int n, m;
    scanf("%d %d", &n, &m);
    char* arr = (char*) malloc(sizeof(char)*n*m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &arr[i*m + j]);   
        }
    }


    // init
    int rows = n - 8 + 1;
    int cols = m - 8 + 1;

    // answer
    int ans = n*m;
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            ans = min(ans, countBoard(arr, m, row, col));
        }
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}