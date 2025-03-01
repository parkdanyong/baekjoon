/*
    title: 미세먼지 안녕!
    tag: implement
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int rows, cols, T, size;
int airPurifier;
int* arr;
int* mem;


void spreadOut() {
    int dust;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 5) continue;

        dust = (int) arr[i] / 5;
        if (i + 1 < size && i % cols + 1 < cols && arr[i + 1] != -1) { // right
            arr[i] -= dust;
            mem[i + 1] += dust;
        }
        if (0 <= i - 1 && 0 <= i % cols - 1 && arr[i - 1] != -1) { // left
            arr[i] -= dust;
            mem[i - 1] += dust;
        }
        if (i + cols < size && arr[i + cols] != -1) { // down
            arr[i] -= dust;
            mem[i + cols] += dust;
        }
        if (0 <= i - cols && arr[i - cols] != -1) { // up
            arr[i] -= dust;
            mem[i - cols] += dust;
        }
    }

    for (int i = 0; i < size; i++) {
        arr[i] += mem[i];
    }
}


void blow() {
    int top_AP = airPurifier - cols;
    int bottom_AP = airPurifier;
    int top_AP_wind = top_AP - cols;
    int bottom_AP_wind = bottom_AP + cols;
    while (top_AP_wind != top_AP || bottom_AP_wind != bottom_AP) {
        if (top_AP_wind / cols == top_AP / cols) { // bottom
            if (top_AP_wind != top_AP) {
                if (arr[top_AP_wind - 1] == -1) arr[top_AP_wind] = 0;
                else arr[top_AP_wind] = arr[top_AP_wind - 1];
                top_AP_wind -= 1; // move
            }
        }
        else if ((top_AP_wind + 1) % cols == 0) { // right
            arr[top_AP_wind] = arr[top_AP_wind + cols];
            top_AP_wind += cols; // move
        }
        else if (top_AP_wind / cols == 0) { // top
            arr[top_AP_wind] = arr[top_AP_wind + 1];
            top_AP_wind += 1; // move
        }
        else if (top_AP_wind % cols == 0) { // left
            arr[top_AP_wind] = arr[top_AP_wind - cols];
            top_AP_wind -= cols; // move
        }
        

        if (bottom_AP_wind / cols == bottom_AP / cols) { // top
            if (bottom_AP_wind != bottom_AP) {
                if (arr[bottom_AP_wind - 1] == -1) arr[bottom_AP_wind] = 0;
                else arr[bottom_AP_wind] = arr[bottom_AP_wind - 1];
                bottom_AP_wind -= 1; // move
            }
        }
        else if ((bottom_AP_wind + 1) % cols == 0) { // right
            arr[bottom_AP_wind] = arr[bottom_AP_wind - cols];
            bottom_AP_wind -= cols; // move
        }
        else if (bottom_AP_wind / cols == rows - 1) { // bottom
            arr[bottom_AP_wind] = arr[bottom_AP_wind + 1];
            bottom_AP_wind += 1; // move
        }
        else if (bottom_AP_wind % cols == 0) { // left
            arr[bottom_AP_wind] = arr[bottom_AP_wind + cols];
            bottom_AP_wind += cols; // move
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &rows, &cols, &T);
    // size = rows * cols;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     if (arr[i] == -1) airPurifier = i;
    // }
    // fclose(file);

    
    // input
    scanf("%d %d %d", &rows, &cols, &T);
    size = rows * cols;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] == -1) airPurifier = i;
    }


    // init
    mem = (int*) calloc(size,sizeof(int));


    // answer
    for (int i = 0; i < T; i++) {
        spreadOut();
        memset(mem, 0, sizeof(int)*size);
        blow();
    }
    int ans = 2;
    for (int i = 0; i < size; i++) {
        ans += arr[i];
    }
    printf("%d\n", ans);


    free(arr);
    free(mem);
    return 0;
}