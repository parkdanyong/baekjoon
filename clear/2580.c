/*
    title: 스도쿠
    tag: backtracking
*/



#include <stdio.h>
#include <stdlib.h>


#define BOARD_SIZE 81


int flag;
int* arr;


void findValid(int* valid, int pos) {
    for (int i = 0; i < 10; i++) {
        valid[i] = 1;
    }

    int cur = pos / 9 * 9; // rows
    for (int i = 0; i < 9; i++) {
        valid[arr[cur + i]] = 0;
    }


    cur = pos % 9; // cols
    for (int i = 0; i < 9; i++) {
        valid[arr[cur + 9*i]] = 0;
    }


    int square = (pos / 27 * 27) + (pos % 9 / 3 * 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            valid[arr[square + 9*i + j]] = 0;
        }
    }
}


void backtrack(int pos) {
    if (pos == BOARD_SIZE) {
        flag = 1;
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("%d ", arr[i]);
            if ((i+1) % 9 == 0) printf("\n");
        }
        return;
    }
    else if (flag) return;
    else if (arr[pos] != 0) {
        backtrack(pos+1);
        return;
    }


    int valid[10];
    findValid(valid, pos);
    for (int i = 1; i <= 9; i++) {
        if (valid[i]) {
            arr[pos] = i;
            backtrack(pos+1);
            arr[pos] = 0;
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // arr = (int*) malloc(sizeof(int)*BOARD_SIZE);
    // for (int i = 0; i < BOARD_SIZE; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    arr = (int*) malloc(sizeof(int)*BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    flag = 0;
    backtrack(0);


    free(arr);
    return 0;
}