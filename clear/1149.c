/*
    title: RGB거리
    tag: dp

    

    pre.R: min value when R was previously selected
    pre.G: min value when G was previously selected
    pre.B: min value when B was previously selected

    new: current incoming G, R, B value

    cur.R: current min value when R is selected
    cur.G: current min value when G is selected
    cur.B: current min value when B is selected

*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int R;
    int G;
    int B;
}node;


int min(int a, int b) {
    return a < b ? a : b;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // node pre, cur, tmp;
    // fscanf(file, "%d %d %d", &pre.R, &pre.G, &pre.B);
    // for (int i = 1; i < n; i++) {
    //     fscanf(file, "%d %d %d", &cur.R, &cur.G, &cur.B);
    //     tmp.R = min(cur.R + pre.G, cur.R + pre.B);
    //     tmp.G = min(cur.G + pre.R, cur.G + pre.B);
    //     tmp.B = min(cur.B + pre.R, cur.B + pre.G);
    //     pre.R = tmp.R;
    //     pre.G = tmp.G;
    //     pre.B = tmp.B;        
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    node pre, cur, new;
    scanf("%d %d %d", &pre.R, &pre.G, &pre.B);
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &new.R, &new.G, &new.B);
        cur.R = min(new.R + pre.G, new.R + pre.B);
        cur.G = min(new.G + pre.R, new.G + pre.B);
        cur.B = min(new.B + pre.R, new.B + pre.G);
        pre.R = cur.R;
        pre.G = cur.G;
        pre.B = cur.B;        
    }


    // answer
    int ans = min(min(pre.R, pre.G), pre.B);
    printf("%d\n", ans);


    return 0;
}