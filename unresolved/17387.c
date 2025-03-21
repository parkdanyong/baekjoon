/*
    title: 선분 교차 2
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


typedef struct Point {
    ll X;
    ll Y;
}Point;




ll ccw(Point a, Point b, Point c) {
    long long cross_product = (b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X);
    if (cross_product > 0) return 1;  
    if (cross_product < 0) return -1;
    return 0;
}


int isOverlapping(Point a, Point b, Point c, Point d) {
    if (a.X > b.X) { Point temp = a; a = b; b = temp; }
    if (c.X > d.X) { Point temp = c; c = d; d = temp; }
    if (b.X < c.X || d.X < a.X) return 0;

    if (a.Y > b.Y) { Point temp = a; a = b; b = temp; }
    if (c.Y > d.Y) { Point temp = c; c = d; d = temp; }
    if (b.Y < c.Y || d.Y < a.Y) return 0;

    return 1;
}


int isIntersect(Point a, Point b, Point c, Point d) {
    int ccw1 = ccw(a, b, c) * ccw(a, b, d);
    int ccw2 = ccw(c, d, a) * ccw(c, d, b);

    if (ccw1 == 0 && ccw2 == 0) {
        return isOverlapping(a, b, c, d);
    }
    return (ccw1 <= 0 && ccw2 <= 0);
}



int main() {
    Point A, B, C, D;
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%lld %lld %lld %lld", &A.X, &A.Y, &B.X, &B.Y);
    // fscanf(file, "%lld %lld %lld %lld", &C.X, &C.Y, &D.X, &D.Y);
    // fclose(file);


    // input
    scanf("%lld %lld %lld %lld", &A.X, &A.Y, &B.X, &B.Y);
    scanf("%lld %lld %lld %lld", &C.X, &C.Y, &D.X, &D.Y);


    // answer
    int ans = isIntersect(A, B, C, D);
    printf("%d\n", ans);


    return 0;
}