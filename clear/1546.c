/*
    title: 평균
    tag: math
*/




#include <stdio.h>
#include <stdlib.h>




int compare(const void* arg1, const void* arg2) {
    int a = *(int*) arg1;
    int b = *(int*) arg2;
    return b - a; // descending order
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    //input
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    // init
    qsort(arr, n, sizeof(int), compare);
    int maxScore = arr[0];
    
    
    // answer
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (double) arr[i] / maxScore * 100;
    }
    ans /= n;
    printf("%0.20lf\n", ans);

    
    
    free(arr);
    return 0;
}