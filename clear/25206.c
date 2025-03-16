/*
    title: 너의 평점은
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


#define BUFFER_MAX_SIZE 100


char* buf;
double ans;
char p[2];
double gp;
double gpa;


double conversion() {
    if (p[0] == 'A') {
        if (p[1] == '+') return 4.5;
        else return 4.0;
    }
    else if (p[0] == 'B') {
        if (p[1] == '+') return 3.5;
        else return 3.0;
    }
    else if (p[0] == 'C') {
        if (p[1] == '+') return 2.5;
        else return 2.0;
    }
    else if (p[0] == 'D') {
        if (p[1] == '+') return 1.5;
        else return 1.0;
    }
    else if (p[0] == 'F') return 0.0;
    else return 5.0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // buf = (char*) malloc(sizeof(char)*BUFFER_MAX_SIZE);
    // ans = 0;
    // gpa = 0;
    // double tmp;
    // for (int i = 0; i < 20; i++) {
    //     fscanf(file, "%s %lf %s", buf, &gp, p);
    //     tmp = conversion();
    //     if (tmp == 5.0) continue;
    //     gpa += gp;
    //     ans += gp*tmp;
    // }
    // printf("%6lf\n", ans / gpa);
    // fclose(file);


    // input
    buf = (char*) malloc(sizeof(char)*BUFFER_MAX_SIZE);
    ans = 0;
    gpa = 0;
    double tmp;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", buf, &gp, p);
        tmp = conversion();
        if (tmp == 5.0) continue;
        gpa += gp;
        ans += gp*tmp;
    }
    printf("%6lf\n", ans / gpa);


    free(buf);
    return 0;
}