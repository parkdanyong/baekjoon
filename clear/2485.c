/*
    title: 가로수
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>


typedef long long ll;


int N;
ll* arr;


ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &N);
    // arr = (ll*) malloc(sizeof(ll)*N);
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%lld", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d", &N);
    arr = (ll*) malloc(sizeof(ll)*N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &arr[i]);
    }


    // answer
    ll* distance = (ll*)malloc((N - 1) * sizeof(ll));
    for (int i = 0; i < N - 1; i++) {
        distance[i] = arr[i + 1] - arr[i];
    }

    int interval_gcd = distance[0];
    for (int i = 1; i < N - 1; i++) {
        interval_gcd = gcd(interval_gcd, distance[i]);
    }

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        ans += (distance[i] / interval_gcd) - 1;
    }

    
    printf("%d\n", ans);


    free(arr);
    free(distance);
    return 0;
}