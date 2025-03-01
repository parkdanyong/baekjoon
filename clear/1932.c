/*
    title: 정수 삼각형
    tag: dp

    Solution
    pre array: max value when each value of the previous layer is selected
    cur array: max value when each value of the current layer is selected
    new array: values ​​of the new layer

*/



#include <stdio.h>
#include <stdlib.h>


int n;
int* pre;
int* cur;
int* new;


int max(int a, int b) {
    return a > b ? a : b;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // pre = (int*) malloc(sizeof(int)*(n+1));
    // cur = (int*) malloc(sizeof(int)*(n+1));
    // new = (int*) malloc(sizeof(int)*(n+1));
    // fscanf(file, "%d", &pre[1]);
    // for (int i = 2; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         fscanf(file, "%d", &new[j]);
    //     }

    //     for (int j = 1; j <= i; j++) {
    //         if (j - 1 == 0) cur[j] = new[j] + pre[j];
    //         else if (j == i) cur[j] = new[j] + pre[j-1];
    //         else cur[j] = max(new[j] + pre[j], new[j] + pre[j-1]);
    //     }

    //     for (int j = 1; j <= i; j++) {
    //         pre[j] = cur[j];
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    pre = (int*) malloc(sizeof(int)*(n+1));
    cur = (int*) malloc(sizeof(int)*(n+1));
    new = (int*) malloc(sizeof(int)*(n+1));
    scanf("%d", &pre[1]);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &new[j]);
        }

        for (int j = 1; j <= i; j++) {
            if (j - 1 == 0) cur[j] = new[j] + pre[j];
            else if (j == i) cur[j] = new[j] + pre[j-1];
            else cur[j] = max(new[j] + pre[j], new[j] + pre[j-1]);
        }

        for (int j = 1; j <= i; j++) {
            pre[j] = cur[j];
        }
    }
    

    // answer
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, pre[i]);
    }
    printf("%d\n", ans);


    free(pre);
    free(cur);
    free(new);
    return 0;   
}