/*
    title: 세 막대
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


int compare(const void* a, const void* b) {
    return *(int*) a - *(int*) b;
}


int main() {
    // input
    int arr[3];
    scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);


    // answer
    qsort(arr, 3, sizeof(int), compare);
    if (arr[0] + arr[1] <= arr[2]) printf("%d\n", (arr[0] + arr[1]) * 2 - 1);
    else printf("%d\n", arr[0] + arr[1] + arr[2]);


    return 0;
}