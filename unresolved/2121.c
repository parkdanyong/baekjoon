/*
    title: 넷이 놀기
    tag: hash
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Point {
    int X;
    int Y;
}Point;



int N;
Point* arr;
int A, B;


int main() {
    FILE* file = fopen("inputFile.txt", "r");
    fscanf(file, "%d", &N);
    arr = (Point*) malloc(sizeof(Point)*N);
    for (int i = 0; i < N; i++) {
        fscanf(file, "%d %d", arr[i].X, arr[i].Y);
    }
    fscanf(file, "%d %d", &A, &B);
    fclose(file);


    // answer
    int ans = 0;





    free(arr);
    return 0;
}