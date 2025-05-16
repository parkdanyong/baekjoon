/*
    title: 골드바흐 파티션
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_BOUND 1000000 


int T, N;
int* arr;
int* stack;
int top;


int upperBound(int n) {
    int low = -1;
    int high = top+1;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (stack[mid] <= n) low = mid;
        else high = mid;
    }
    return high;
}


int binarySearch(int n, int min) {
    int low = min;
    int high = top;
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (n < stack[mid]) high = mid-1;
        else if (stack[mid] < n) low = mid+1;
        else return 1;
    }
    return 0;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &T);
    // // init
    // arr = (int*) calloc(MAX_BOUND, sizeof(int)); // about 4MG
    // arr[0] = 1;
    // arr[1] = 1;
    // for (int i = 2; i < MAX_BOUND; i++) {
    //     for (int j = 2; j*i < MAX_BOUND; j++) {
    //         arr[i*j] = 1;
    //     }
    // }
    // stack = (int*) malloc(sizeof(int)*MAX_BOUND);
    // top = -1;
    // for (int i = 2; i < MAX_BOUND; i++) {
    //     if (!arr[i]) stack[++top] = i;
    // }
    // // input
    // int ans = 0;
    // int ub;
    // clock_t start = clock();
    // for (int t = 0; t < T; t++) {
    //     fscanf(file, "%d", &N);
    //     // answer
    //     ans = 0;
    //     ub = upperBound(N);
    //     for (int i = 0; i < ub; i++) {
    //         if (binarySearch(N - stack[i], i)) ans += 1;
    //     }
    //     printf("%d\n", ans);
    // }
    // clock_t end = clock();
    // printf("top: %d\n", top);
    // printf("%.10lf", (double)(end - start) / CLOCKS_PER_SEC);
    // fclose(file);


    
    // init
    arr = (int*) calloc(MAX_BOUND, sizeof(int)); // about 4MG
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < MAX_BOUND; i++) {
        for (int j = 2; j*i < MAX_BOUND; j++) {
            arr[i*j] = 1;
        }
    }
    stack = (int*) malloc(sizeof(int)*MAX_BOUND);
    top = -1;
    for (int i = 2; i < MAX_BOUND; i++) {
        if (!arr[i]) stack[++top] = i;
    }
    // input
    scanf("%d", &T);
    int ans = 0;
    int ub;
    for (int t = 0; t < T; t++) {
        scanf("%d", &N);
        // answer
        ans = 0;
        ub = upperBound(N);
        for (int i = 0; i < ub; i++) {
            if (binarySearch(N - stack[i], i)) ans += 1;
        }
        printf("%d\n", ans);
    }


    free(arr);
    free(stack);
    return 0;
}