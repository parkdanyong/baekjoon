/*
    title: 2048 (Easy)
    tag: brute force, backtracking
*/



#include <stdio.h>
#include <stdlib.h>


#define BOARD_MAX_SIZE 400
#define max(X, Y) (X) > (Y) ? (X) : (Y)


int N, size, ans;


void backtracking(int* preBoard, int count) {
    if (count >= 5) {
        for (int i = 0; i < size; i++) {
            ans = max(ans, preBoard[i]);
        }
        return;
    }

    int board[BOARD_MAX_SIZE];
    int lastPos;
    for (int i = 0; i < N; i++) { // left
        board[N*i] = preBoard[N*i];
        lastPos = 0;
        for (int j = 1; j < N; j++) {
            if (board[N*i + lastPos] == 0) board[N*i + lastPos] = preBoard[N*i + j]; 
            else if (board[N*i + lastPos] == preBoard[N*i + j]) {
                board[N*i + lastPos] += board[N*i + lastPos];
                lastPos += 1;
                board[N*i + lastPos] = 0;
            }
            else {
                lastPos += 1;
                board[N*i + lastPos] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);
    for (int i = 0; i < N; i++) { // right
        board[N*i + N-1] = preBoard[N*i + N-1];
        lastPos = N-1;
        for (int j = N-2; j >= 0; j--) {
            if (board[N*i + lastPos] == 0) board[N*i + lastPos] = preBoard[N*i + j]; 
            else if (board[N*i + lastPos] == preBoard[N*i + j]) {
                board[N*i + lastPos] += board[N*i + lastPos];
                lastPos -= 1;
                board[N*i + lastPos] = 0;
            }
            else {
                lastPos -= 1;
                board[N*i + lastPos] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);
    for (int j = 0; j < N; j++) { // up
        board[j] = preBoard[j];
        lastPos = 0;
        for (int i = 1; i < N; i++) {
            if (board[N*lastPos + j] == 0) board[N*lastPos + j] = preBoard[N*i + j];
            else if (board[N*lastPos + j] == preBoard[N*i + j]) {
                board[N*lastPos + j] += board[N*lastPos + j];
                lastPos += 1;
                board[N*lastPos + j] = 0;
            }
            else {
                lastPos += 1;
                board[N*lastPos + j] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);
    for (int j = 0; j < N; j++) { // down
        board[N*(N-1) + j] = preBoard[N*(N-1) + j];
        lastPos = N-1;
        for (int i = N-2; i >= 0; i--) {
            if (board[N*lastPos + j] == 0) board[N*lastPos + j] = preBoard[N*i + j];
            else if (board[N*lastPos + j] == preBoard[N*i + j]) {
                board[N*lastPos + j] += board[N*lastPos + j];
                lastPos -= 1;
                board[N*lastPos + j] = 0;
            }
            else {
                lastPos -= 1;
                board[N*lastPos + j] = preBoard[N*i + j]; 
            }
        }
    }
    backtracking(board, count+1);
}  



int main() {
    FILE* file = fopen("inputFile.txt", "r");
    fscanf(file, "%d", &N);
    size = N * N;
    ans = 0;
    int board[BOARD_MAX_SIZE];
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", board[i]);
    }
    backtracking(board, 0);
    printf("%d\n", ans);
    fclose(file);


    return 0;
}