/*
    title: 좌표 정렬하기
    tag: sorting
*/




#include <stdio.h>
#include <stdlib.h>



typedef struct Point {
    int x;
    int y;
}point;


int compare(const void* arg1, const void* arg2) {
    point* a = (point*) arg1;
    point* b = (point*) arg2;

    int cmp = a->x - b->x;
    if (cmp == 0) cmp = a->y - b->y;
    return cmp;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n = 0;
    // fscanf(file, "%d", &n);
    // point* arr = (point*) malloc(sizeof(point)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d %d", &arr[i].x, &arr[i].y);
    // }
    // fclose(file);


    // input
    int n = 0;
    scanf("%d", &n);
    point* arr = (point*) malloc(sizeof(point)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }


    // init
    qsort(arr, n, sizeof(point), compare);


    // answer
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }


    free(arr);
    return 0;
}