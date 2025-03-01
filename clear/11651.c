/*
    title: 좌표 정렬하기 2
    tag: sorting
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Point {
    int X;
    int Y;
}point;


int compare(const void* arg1, const void* arg2) {
    point* a = (point*) arg1;
    point* b = (point*) arg2;
    
    int cmp = a->Y - b->Y;
    if (cmp == 0) return a->X - b->X;
    else return cmp;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // point* arr = (point*) malloc(sizeof(point)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d %d", &arr[i].X, &arr[i].Y);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    point* arr = (point*) malloc(sizeof(point)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].X, &arr[i].Y);
    }


    // init
    qsort(arr, n, sizeof(point), compare);


    // answer
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].X, arr[i].Y);
    }


    free(arr);
    return 0;
}