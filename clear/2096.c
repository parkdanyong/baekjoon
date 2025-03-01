/*
    title: 내려가기
    tag: dp, sliding window
*/



#include <stdio.h>
#include <stdlib.h>


int max(int a, int b) {
    return a > b ? a : b;
}


int min(int a, int b) {
    return a < b ? a : b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // int preMax[3];
    // int preMin[3];
    // int curMax[3];
    // int curMin[3];
    // int new[3];
    // fscanf(file, "%d %d %d", &new[0], &new[1], &new[2]);
    // for (int i = 0; i < 3; i++) {
    //     preMax[i] = new[i];
    //     preMin[i] = new[i];
    // }
    // for (int i = 1; i < n; i++) {
    //     fscanf(file, "%d %d %d", &new[0], &new[1], &new[2]);
        
    //     curMax[0] = max(preMax[0], preMax[1]) + new[0];
    //     curMax[1] = max(max(preMax[0], preMax[1]), preMax[2]) + new[1];
    //     curMax[2] = max(preMax[1], preMax[2]) + new[2];
    //     curMin[0] = min(preMin[0], preMin[1]) + new[0];
    //     curMin[1] = min(min(preMin[0], preMin[1]), preMin[2]) + new[1];
    //     curMin[2] = min(preMin[1], preMin[2]) + new[2];

    //     for (int i = 0; i < 3; i++) {
    //         preMax[i] = curMax[i];
    //         preMin[i] = curMin[i];
    //     }
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    int preMax[3];
    int preMin[3];
    int curMax[3];
    int curMin[3];
    int new[3];
    scanf("%d %d %d", &new[0], &new[1], &new[2]);
    for (int i = 0; i < 3; i++) {
        preMax[i] = new[i];
        preMin[i] = new[i];
    }
    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &new[0], &new[1], &new[2]);
        
        curMax[0] = max(preMax[0], preMax[1]) + new[0];
        curMax[1] = max(max(preMax[0], preMax[1]), preMax[2]) + new[1];
        curMax[2] = max(preMax[1], preMax[2]) + new[2];
        curMin[0] = min(preMin[0], preMin[1]) + new[0];
        curMin[1] = min(min(preMin[0], preMin[1]), preMin[2]) + new[1];
        curMin[2] = min(preMin[1], preMin[2]) + new[2];

        for (int i = 0; i < 3; i++) {
            preMax[i] = curMax[i];
            preMin[i] = curMin[i];
        }
    }


    // answer
    printf("%d %d\n", max(max(preMax[0], preMax[1]), preMax[2]), min(min(preMin[0], preMin[1]), preMin[2]));


    return 0;
}