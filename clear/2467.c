/*
    title: 용액
    tag: binary search, two pointer
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define INF 2000000000


int n;
int* arr;



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // answer
    int minVal = INF;
    int a = 0, b = 0;
    int L = 0, R = n-1;
    int cmp;
    while (L < R) {
        if (minVal == 0) break;
        cmp = arr[L] + arr[R];
        if (abs(cmp) < minVal) {
            minVal = abs(cmp);
            a = arr[L];
            b = arr[R];
        }
        if (cmp < 0) L += 1;
        else R -= 1;
    }
    if (a > b) printf("%d %d\n", b, a);
    else printf("%d %d\n", a, b);


    free(arr);
    return 0;
}