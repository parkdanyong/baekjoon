/*
    title: 랜선 자르기
    tag: parameter search

*/




#include <stdio.h>
#include <stdlib.h>


typedef long long ll;



int compare(const void* a, const void* b) {
    return *(int*) b - *(int*) a; // descending order
}


int isSatisfy(int* lan, int size, int n, ll len) {
    ll sum = 0;
    int tmp = 0;
    
    for (int i = 0; i < size; i++) {
        tmp = (int) lan[i] / len;
        if (tmp == 0) break;
        sum += tmp;
        if (sum >= n) return 1;
    }

    return 0;
} 



ll upperBound(int* lan, int size, int n) {
    ll low = 0;
    ll high = (ll) lan[0] + 1;
    ll mid = 0;

    while (low + 1 < high) {
        mid = low + (high - low) / 2;
        if (isSatisfy(lan, size, n, mid)) low = mid;
        else high = mid;
    }

    return high;
}




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int k, n;
    // fscanf(file, "%d %d", &k, &n);
    // int* lan = (int*) malloc(sizeof(int)*k);
    // for (int i = 0; i < k; i++) {
    //     fscanf(file, "%d", &lan[i]);
    // }
    // fclose(file);


    // input
    int k, n;
    scanf("%d %d", &k, &n);
    int* lan = (int*) malloc(sizeof(int)*k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &lan[i]);
    }


    // init
    qsort(lan, k, sizeof(int), compare);


    // answer
    printf("%d\n", upperBound(lan, k, n) - 1);


 
    free(lan);
    return 0;
}