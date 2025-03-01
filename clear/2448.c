/*
    title: 별 찍기 - 11
    tag: recursion
*/



#include <stdio.h>
#include <stdlib.h>


int main() {
    // input
    int n;
    scanf("%d", &n);


    // init
    int bottom = n / 3;
    int MAX_SIZE = bottom * 5 + bottom - 1;
    // printf("%d %d\n", bottom, MAX_SIZE);
    char* p1 = (char*) malloc(sizeof(char)*(MAX_SIZE + 1));
    char* p2 = (char*) malloc(sizeof(char)*(MAX_SIZE + 1));
    char* p3 = (char*) malloc(sizeof(char)*(MAX_SIZE + 1));
    for (int i = 0; i < (MAX_SIZE + 1); i++) {
        p1[i] = ' ';
        p2[i] = ' ';
        p3[i] = ' ';
    }
    p1[n-1] = '*';
    int layer = 1;
    int pattern = 1;


    // answer
    while (layer <= n) {
        pattern = layer % 3;

        if (pattern == 1) {
            for (int i = 0; i < MAX_SIZE; i++) {
                printf("%c", p1[i]);
                if (p1[i-1] == '*' || p1[i+1] == '*') p2[i] = '*';
                else p2[i] = ' ';
            }
        }
        else if (pattern == 2) {
            for (int i = 0; i < MAX_SIZE; i++) {
                printf("%c", p2[i]);
                if (p2[i-1] == '*' || p2[i] == '*' || p2[i+1] == '*') p3[i] = '*';
                else p3[i] = ' ';
            }
        } 
        else {
            for (int i = 0; i < MAX_SIZE; i++) {
                printf("%c", p3[i]);
                if (p3[i-1] == '*' && p3[i] == ' ' && p3[i+1] == ' ') p1[i] = '*';
                else if (p3[i-1] == ' ' && p3[i] == ' ' && p3[i+1] == '*') p1[i] = '*';
                else p1[i] = ' ';
            }
        }
        printf("\n");
        layer += 1;
    }
    

    free(p1);
    p1 = NULL;
    free(p2);
    p2 = NULL;
    free(p3);
    p3 = NULL;
    return 0;
}   