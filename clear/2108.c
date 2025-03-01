/*
    title: 통계학
    tag: math, sorting
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // int* count = (int*) calloc(8001, sizeof(int));
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     count[4000 + arr[i]] += 1;
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    int* arr = (int*) malloc(sizeof(int)*n);
    int* count = (int*) calloc(8001, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[4000 + arr[i]] += 1;
    }


    // init
    qsort(arr, n, sizeof(int), compare);


    // answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += arr[i];
    }
    printf("%d\n", (int) floor((double) ans / (double) n + 0.5));

    ans = arr[(int) n / 2];
    printf("%d\n", ans);

    int flag = 0;
    int cmp = count[0];
    ans = -4000;
    for (int i = 1; i <= 8000; i++) {
        if (cmp < count[i]) {
            cmp = count[i];
            ans = i - 4000;
            flag = 0;
        }
        else if (count[i] == cmp && flag == 0) {
            flag = 1;
            ans = i - 4000;
        }
    }
    printf("%d\n", ans);

    ans = arr[n-1] - arr[0];
    printf("%d\n", ans);



    free(arr);
    free(count);
    return 0;
}