/*
    title: 구간 합 구하기 5
    tag: dp, prefix sum
*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    int n, T;
    // fscanf(file, "%d %d", &n, &T);
    scanf("%d %d", &n, &T);
    int size = (n+1) * n;
    int* arr = (int*) malloc(sizeof(int)*size);
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (i % (n+1) == 0) {
            arr[i] = 0;
            sum = 0;
            continue;
        }
        // fscanf(file, "%d", &arr[i]);
        scanf("%d", &arr[i]);
        sum += arr[i];
        arr[i] = sum;
    }
    

    // init
    int x1, y1, x2, y2;


    // answer
    int ans = 0;
    for (int i = 0; i < T; i++) {
        // fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int j = x1 - 1; j < x2; j++) {
            ans += arr[(n+1)*j + y2] - arr[(n+1)*j + y1-1];
        }
        printf("%d\n", ans);
        ans = 0;
    }

    
    // fclose(file);
    free(arr);
    return 0;
}