/*
    title: 사탕 배달
    tag: math, sort, greedy algorithm, 누적합


*/




#include <stdio.h>
#include <stdlib.h>




int compare(const void* a, const void* b) {
    int fate_1 = *(int*) a;
    int fate_2 = *(int*) b;
    return fate_2 - fate_1;
}


long long max(long a, long b) {
    return a < b ? b : a;
}


int min(int a, int b) {
    return a > b ? b : a;
}


void prefixSum(long long* candy, int size) {
    long long sum = 0;
    long long tmp = 0;
    for (int i = 0; i < size; i++) {
        tmp = candy[i];
        candy[i] = sum;
        sum += tmp;
    }
}



int main() {
    // file input
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, weight;
    // fscanf(file, "%d %d", &n, &weight);
    // long long* candy_3 = (long long*) malloc(sizeof(long long)*(n+1));
    // long long* candy_5 = (long long*) malloc(sizeof(long long)*(n+1));
    // int size_3 = 0, size_5 = 0;
    // int type, sugar;
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%d %d", &type, &sugar);
    //     if (type == 3) candy_3[size_3++] = sugar;
    //     else candy_5[size_5++] = sugar;
    // }
    

    // input
    int n, weight;
    scanf("%d %d", &n, &weight);

    long long* candy_3 = (long long*) malloc(sizeof(long long)*(n+1));
    long long* candy_5 = (long long*) malloc(sizeof(long long)*(n+1));
    int size_3 = 0, size_5 = 0;
    int type, sugar;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &type, &sugar);
        if (type == 3) candy_3[size_3++] = sugar;
        else candy_5[size_5++] = sugar;
    }


    // init
    qsort(candy_3, size_3, sizeof(long long), compare);
    qsort(candy_5, size_5, sizeof(long long), compare);
    prefixSum(candy_3, size_3 + 1);
    prefixSum(candy_5, size_5 + 1);


    // answer
    int range_x = min(size_3, (int) weight / 3); 
    int y = 0; 
    long long maxSugar = 0;
    for (int x = 0; x < range_x + 1; x++) {
        y = min(size_5, (int) ((weight - 3 * x) / 5));
        maxSugar = max(maxSugar, candy_3[x] + candy_5[y]);
    }
    printf("%lld\n", maxSugar);
    

    free(candy_3);
    free(candy_5);
    return 0;
}