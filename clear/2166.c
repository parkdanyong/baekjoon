/*
    title: 다각형의 면적
    tag: geometry
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef long long ll;


typedef struct Point {
    ll x;
    ll y;
}point;


int n;
point* arr;


double triangle(point p1, point p2) {
    ll x1 = arr[0].x, y1 = arr[0].y;
    ll x2 = p1.x, y2 = p1.y;
    ll x3 = p2.x, y3 = p2.y;
    return (double) (x1*y2 + x2*y3 + x3*y1 - x2*y1 - x3*y2 - x1*y3) / 2;
}


int main() {
    // FILE* file =  fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (point*) malloc(sizeof(point)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%lld %lld", &arr[i].x, &arr[i].y);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (point*) malloc(sizeof(point)*n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }

    
    // answer
    double ans = 0;
    for (int i = 1; i < n-1; i++) {
        ans += triangle(arr[i], arr[i+1]);
    }
    if (ans < 0) printf("%.1f", -floor(ans*10 + 0.5)/10);
    else printf("%.1f", floor(ans*10 + 0.5)/10);


    free(arr);
    return 0;
}