/*
    title: 2048 (Easy)
    tag: brute force, backtracking
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BOARD_MAX_SIZE 400
#define max(X, Y) (X) > (Y) ? (X) : (Y)


int N, size, ans;


void backtracking(int* preBoard, int count) {
    // printf("count: %d\n", count);
    // for (int i = 0; i < size; i++) {
    //     printf("%d ", preBoard[i]);
    //     if ((i+1) % N == 0) printf("\n");
    // }
    if (count >= 5) {
        for (int i = 0; i < size; i++) {
            ans = max(ans, preBoard[i]);
        }
        return;
    }

    // left
    int* board = (int*) calloc(size, sizeof(int));
    int lastPos;
    for (int i = 0; i < N; i++) { 
        board[N*i] = preBoard[N*i];
        lastPos = 0;
        for (int j = 1; j < N; j++) {
            if (preBoard[N*i + j] == 0) continue;
            else if (board[N*i + lastPos] == 0) board[N*i + lastPos] = preBoard[N*i + j]; 
            else if (board[N*i + lastPos] == preBoard[N*i + j]) {
                board[N*i + lastPos] *= 2;
                lastPos += 1;
            }
            else {
                lastPos += 1;
                board[N*i + lastPos] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);

    // right
    memset(board, 0, sizeof(int)*size);
    for (int i = 0; i < N; i++) { 
        board[N*i + N-1] = preBoard[N*i + N-1];
        lastPos = N-1;
        for (int j = N-2; j >= 0; j--) {
            if (preBoard[N*i + j] == 0) continue;
            else if (board[N*i + lastPos] == 0) board[N*i + lastPos] = preBoard[N*i + j]; 
            else if (board[N*i + lastPos] == preBoard[N*i + j]) {
                board[N*i + lastPos] *= 2;
                lastPos -= 1;
            }
            else {
                lastPos -= 1;
                board[N*i + lastPos] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);

    // up
    memset(board, 0, sizeof(int)*size);
    for (int j = 0; j < N; j++) { 
        board[j] = preBoard[j];
        lastPos = 0;
        for (int i = 1; i < N; i++) {
            if (preBoard[N*i + j] == 0) continue;
            else if (board[N*lastPos + j] == 0) board[N*lastPos + j] = preBoard[N*i + j];
            else if (board[N*lastPos + j] == preBoard[N*i + j]) {
                board[N*lastPos + j] *= 2;
                lastPos += 1;
            }
            else {
                lastPos += 1;
                board[N*lastPos + j] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);

    // down
    memset(board, 0, sizeof(int)*size);
    for (int j = 0; j < N; j++) { 
        board[N*(N-1) + j] = preBoard[N*(N-1) + j];
        lastPos = N-1;
        for (int i = N-2; i >= 0; i--) {
            if (preBoard[N*i + j] == 0) continue;
            else if (board[N*lastPos + j] == 0) board[N*lastPos + j] = preBoard[N*i + j];
            else if (board[N*lastPos + j] == preBoard[N*i + j]) {
                board[N*lastPos + j] *= 2;
                lastPos -= 1;
            }
            else {
                lastPos -= 1;
                board[N*lastPos + j] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);
    free(board);
}  



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // size = N * N;
    // ans = 0;
    // int* board = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &board[i]);
    // }
    // backtracking(board, 0);
    // printf("%d\n", ans);
    // fclose(file);


    // input
    scanf("%d", &N);
    size = N * N;
    ans = 0;
    int* board = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &board[i]);
    }
    backtracking(board, 0);
    printf("%d\n", ans);


    free(board);
    return 0;
}