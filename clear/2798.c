/*
    title: 블랙잭
    tag: brute force algorithm
*/




#include <stdio.h>
#include <stdlib.h>




int compare(const void* a, const void* b) {
    return *(int*) b - *(int*) a; // descending order
}



int bruteForce(int* arr, int n, int m) {
    int ans = 0;
    int onion1 = 0;
    int onion2 = 0;
    for (int i = 0; i < n; i++) {
        onion1 = arr[i];
        if (onion1 > m) continue;
        for (int j = i + 1; j < n; j++) {
            onion2 = onion1 + arr[j];
            if (onion2 > m) continue;
            for (int k = j + 1; k < n; k++) {
                if (onion2 + arr[k] <= m && ans < onion2 + arr[k]) ans = onion2 + arr[k];
            }
        }
    }

    return ans;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, m;
    // fscanf(file, "%d %d", &n, &m);
    // int* arr = (int*) malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    int n, m;
    scanf("%d %d", &n, &m);
    int* arr = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    qsort(arr, n, sizeof(int), compare);
    

    // answer
    int ans = bruteForce(arr, n, m);
    printf("%d\n", ans);

    


    free(arr);
    return 0;
}