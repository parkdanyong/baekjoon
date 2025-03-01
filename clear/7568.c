/*
    title: 덩치
    tag: brute force
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Body {
    int weight;
    int height;
}body;



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // body* arr = (body*) malloc(sizeof(body)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d %d", &arr[i].weight, &arr[i].height);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    body* arr = (body*) malloc(sizeof(body)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].weight, &arr[i].height);
    }


    // answer
    int ans = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i].weight < arr[j].weight && arr[i].height < arr[j].height) ans += 1;
        }
        printf("%d ", ans);
        ans = 1;
    }
    printf("\n");


    free(arr);
    return 0;
}