/*
    title: 수 나누기 게임
    tag: math, brute force, Sieve of Eratosthenes
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_NUM 1000000



int n;
int* arr;
int* card;
int* mem;



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


    // init
    card = (int*) calloc(MAX_NUM+1, sizeof(int));
    for (int i = 0; i < n; i++) {
        card[arr[i]] = 1;
    }
    mem = (int*) calloc(MAX_NUM+1, sizeof(int));


    // answer
    for (int i = 0; i < n; i++) {
        for (int j = 2; arr[i]*j <= MAX_NUM; j++) {
            if (card[arr[i]*j]) {
                mem[arr[i]*j] -= 1;
                mem[arr[i]] += 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", mem[arr[i]]);
    }
    printf("\n");


    free(arr); 
    free(card);
    free(mem);
    return 0;
}