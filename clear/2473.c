/*
    title: 세 용액
    tag: binary search, Two-Pointer
*/



#include <stdio.h>
#include <stdlib.h>


#define INF 5000000000


typedef long long ll;


int n;
ll* arr;
ll ans;
ll liquid[3];


int compare(const void* a, const void* b) {
    return (int) (*(ll*) a - *(ll*) b);
}


ll ABS(ll val) {
    if (val < 0) val = -val;
    return val;
}



void Bsearch(int mid) {
    int low = 0;
    int high = n-1;
    ll cmp;
    while (low < high) {
        if (low == mid) {
            low += 1;
            continue;
        }
        else if (high == mid) {
            high -= 1;
            continue;
        }

        cmp = arr[low] + arr[high] + arr[mid];
        if (ABS(cmp) < ans) {
            ans = ABS(cmp);
            liquid[0] = arr[low];
            liquid[1] = arr[mid];
            liquid[2] = arr[high];
        }

        if (cmp < 0) low += 1;
        else if (cmp > 0) high -= 1;
        else return;
    }
}   


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (ll*) malloc(sizeof(ll)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (ll*) malloc(sizeof(ll)*n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }


    // init
    qsort(arr, n, sizeof(ll), compare);


    // answer
    ans = INF;
    for (int i = 0; i < n; i++) {
        Bsearch(i);
        if (ans == 0) break;
    }
    qsort(liquid, 3, sizeof(ll), compare);
    printf("%lld %lld %lld\n", liquid[0], liquid[1], liquid[2]);
    

    free(arr);
    return 0;
}