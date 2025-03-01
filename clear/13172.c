/*
    title: Σ
    tag: math, Fermat’s little theorem, Modular Multiplicative Inverse

    
*/



#include <stdio.h>
#include <stdlib.h>


#define PRIME_NUMBER 1000000007


typedef long long ll;


typedef struct Pair {
    ll v1;
    ll v2;
}pair;


ll power(ll a, ll b) {
    if (b == 0) return 1;

    ll val;
    val = power(a, b/2);
    val = (val * val) % PRIME_NUMBER;
    if (b % 2 == 1) {
        val = val * a % PRIME_NUMBER;
    }
    return val;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // pair* arr = (pair*) malloc(sizeof(pair)*n);
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%lld %lld", &arr[i].v1, &arr[i].v2);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    pair* arr = (pair*) malloc(sizeof(pair)*n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &arr[i].v1, &arr[i].v2);
    }


    // answer
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + arr[i].v2 * power(arr[i].v1, PRIME_NUMBER - 2)) % PRIME_NUMBER;
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}