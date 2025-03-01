/*
    title: 마인크래프트
    tag: implement, brute force


    The least time.
    If there are multiple answers, the highest height is priority.
*/



#include <stdio.h>
#include <stdlib.h>


int rows, cols, blocks;
int size;
int* arr;
int high, low;



int max(int a, int b) {
    return a > b ? a : b;
}


int min(int a, int b) {
    return a < b  ? a : b;
}


void removeBlocks() {
    for (int i = 0; i < size; i++) {
        if (arr[i] == high) {
            blocks += 1;
            arr[i] -= 1;
        }
    }
    high -= 1;
}


void setBlocks() {
    for (int i = 0; i < size; i++) {
        if (arr[i] == low) {
            arr[i] += 1;
            blocks -= 1;
        } 
    }
    low += 1;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &rows, &cols, &blocks);
    // size = rows*cols;
    // high = 0;
    // low = 256;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     low = min(low, arr[i]);
    //     high = max(high, arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d %d %d", &rows, &cols, &blocks);
    size = rows*cols;
    high = 0;
    low = 256;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }


    // answer
    int up = 0; // block setting time
    int down = 0; // block removing time
    int ans = 0; // time
    // printf("time: %d low: %d high: %d\n", ans, low, high);
    while (1) {
        if (low == high) break;
        up = 0;
        down = 0;
        
        
        for (int i = 0; i < size; i++) {
            if (arr[i] == low) up += 1;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] == high) down += 2;
        }

        if (up <= blocks && up <= down) {
            setBlocks();
            ans += up;
        }
        else {
            removeBlocks();
            ans += down;
        }
        // printf("time: %d low: %d high: %d\n", ans, low, high);
    }
    printf("%d %d\n", ans, high);
    


    free(arr);
    return 0;
}