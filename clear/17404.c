/*
    title: RGB거리 2
    tag: dp

*/



#include <stdio.h>
#include <stdlib.h>


#define INF 1000001


typedef struct Color {
    int R;
    int G;
    int B;
}color;


int n;
color* arr;


int min(int a, int b) {
    return a < b ? a : b;
}


int minWeight(int startColor, int startVal) {
    color pre = {INF, INF, INF}, cur, new;
    if (startColor == 0) pre.R = startVal;
    else if (startColor == 1) pre.G = startVal;
    else pre.B = startVal;

    for (int i = 1; i < n; i++) {
        new = arr[i];
        cur.R = min(pre.G, pre.B) + new.R;
        cur.G = min(pre.R, pre.B) + new.G;
        cur.B = min(pre.R, pre.G) + new.B;
        pre.R = cur.R;
        pre.G = cur.G;
        pre.B = cur.B;
    }


    if (startColor == 0) pre.R = INF;
    else if (startColor == 1) pre.G = INF;
    else pre.B = INF;
    int result = min(min(pre.R, pre.G), pre.B);
    return result;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (color*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d %d %d", &arr[i].R, &arr[i].G, &arr[i].B);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (color*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].R, &arr[i].G, &arr[i].B);
    }


    // answer
    int cmp;
    int ans = INF;
    int first[3] = {arr[0].R, arr[0].G, arr[0].B};
    for (int i = 0; i < 3; i++) {
        cmp = minWeight(i, first[i]);
        ans = min(ans, cmp);
    }
    printf("%d\n", ans);

    
    free(arr);
    return 0;
}