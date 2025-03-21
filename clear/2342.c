/*
    title: Dance Dance Revolution
    tag: dp, Complete Search
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_LEN 100000
#define INF 500000
#define min(X, Y) (X) < (Y) ? (X) : (Y)




int weight[5][5] = {
    {0, 2, 2, 2, 2}, 
    {0, 1, 3, 4, 3}, 
    {0, 3, 1, 3, 4}, 
    {0, 4, 3, 1, 3}, 
    {0, 3, 4, 3, 1}
};
int arr[MAX_LEN+1][5][5];


void initArr() {
    for (int i = 0; i <= MAX_LEN; i++) {
        for (int L = 0; L < 5; L++) {
            for (int R = 0; R < 5; R++) {
                arr[i][L][R] = INF;
            }
        }
    }
    arr[0][0][0] = 0;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // initArr();
    // int cur = 0;
    // int pos;
    // while (1) {
    //     fscanf(file, "%d", &pos);
    //     if (pos == 0) break;
        
    //     cur += 1;
    //     for (int L = 0; L < 5; L++) {
    //         for (int R = 0; R < 5; R++) {
    //             // move left
    //             if (pos != R) arr[cur][pos][R] = min(arr[cur][pos][R], arr[cur-1][L][R] + weight[L][pos]);
    //             // move right
    //             if (pos != L) arr[cur][L][pos] = min(arr[cur][L][pos], arr[cur-1][L][R] + weight[R][pos]);   
    //         }
    //     }
    // }
    // int ans = INF;
    // for (int L = 0; L < 5; L++) {
    //     for (int R = 0; R < 5; R++) {
    //         ans = min(ans, arr[cur][L][R]);
    //     }
    // }
    // printf("%d\n", ans);
    // fclose(file);


    // answeL
    initArr();
    int cur = 0;
    int pos;
    while (1) {
        scanf("%d", &pos);
        if (pos == 0) break;
        
        cur += 1;
        for (int L = 0; L < 5; L++) { // pre left pos
            for (int R = 0; R < 5; R++) { // pre right pos
                // move left
                if (pos != R) arr[cur][pos][R] = min(arr[cur][pos][R], arr[cur-1][L][R] + weight[L][pos]);
                // move right
                if (pos != L) arr[cur][L][pos] = min(arr[cur][L][pos], arr[cur-1][L][R] + weight[R][pos]);   
            }
        }
    }


    // answer
    int ans = INF;
    for (int L = 0; L < 5; L++) {
        for (int R = 0; R < 5; R++) {
            ans = min(ans, arr[cur][L][R]);
        }
    }
    printf("%d\n", ans);
    
    
    return 0;
}