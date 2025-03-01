/*
    title: 부분합
    tag: Prefix Sum, Two pointer
*/



#include <stdio.h>
#include <stdlib.h>


int N, S;
int* arr;


int min(int a, int b) {
    return a < b ? a : b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &N, &S);
    // arr = (int*) malloc(sizeof(int)*(N+1));
    // arr[0] = 0;
    // int low = 0;
    // int high = -1;
    // for (int i = 1; i <= N; i++) {
    //     fscanf(file, "%d", &arr[i]);
    //     arr[i] += arr[i-1];
    //     if (high == -1 && S <= arr[i]) high = i;
    // }
    // fclose(file);


    // input
    scanf("%d %d", &N, &S);
    arr = (int*) malloc(sizeof(int)*(N+1));
    arr[0] = 0;
    int low = 0;
    int high = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i-1];
        if (high == -1 && S <= arr[i]) high = i;
    }


    // answer
    int ans = 100001;
    while (low < high && high <= N) {
        if (S <= arr[high] - arr[low]) {
            ans = min(ans, high - low);
            low += 1;
        }
        else high += 1;   
    }
    if (ans == 100001) ans = 0;
    printf("%d\n" ,ans);


    free(arr);
    return 0;
}