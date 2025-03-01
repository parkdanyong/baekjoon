/*
    title: 과일 탕후루
    tag: implement, brute force, two pointers


    Solution 1 -> timeout tlqkf
    Start 0 and add the number of fruits until the counts are greater than 2.
    Then move one to the right and start again.


    Solution 2
    Start 0 and add the number of fruits.
    If the counts are greater than 2, remove the left side.

*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int type;
    int count;
}node;


int max(int a, int b) {
    return a >= b ? a : b;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // node* arr = (node*) malloc(sizeof(node)*n);
    // int size = 1;
    // fscanf(file, "%d", &arr[0].type);
    // arr[0].count = 1;
    // int tmp;
    // for (int i = 1; i < n; i++) {
    //     fscanf(file, "%d", &tmp);
    //     if (tmp == arr[size-1].type) arr[size-1].count += 1;
    //     else arr[size++] = (node) {tmp, 1};
    // }
    // fclose(file);



    // input
    int n;
    scanf("%d", &n);
    node* arr = (node*) malloc(sizeof(node)*n);
    int size = 1;
    scanf("%d", &arr[0].type);
    arr[0].count = 1;
    int tmp;
    for (int i = 1; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp == arr[size-1].type) arr[size-1].count += 1;
        else arr[size++] = (node) {tmp, 1};
    }
    

    // init
    int fruit1 = 0;
    int fruit2 = 0;
    int cmp = 0;


    // answer 1
    // int ans = 0;
    // for (int i = 0; i < size; i++) {
    //     fruit1 = arr[i].type;
    //     fruit2 = 0;
    //     cmp = arr[i].count;

    //     for (int j = i + 1; j < size; j++) {
    //         if (arr[j].type == fruit1 || arr[j].type == fruit2) cmp += arr[j].count;
    //         else if (fruit2 == 0) {
    //             fruit2 = arr[j].type;
    //             cmp += arr[j].count;
    //         }
    //         else break;
    //     }
    //     ans = max(ans, cmp);
    // }
    // printf("%d\n", ans);


    // answer 2
    fruit1 = arr[0].type;
    cmp = arr[0].count;
    int ans = cmp;
    for (int i = 1; i < size; i++) {
        if (arr[i].type != fruit1 && arr[i].type != fruit2) {
            ans = max(ans, cmp);
            fruit1 = arr[i-1].type;
            fruit2 = arr[i].type;
            cmp = arr[i-1].count + arr[i].count;
        }
        else cmp += arr[i].count;
        ans = max(ans, cmp);
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}
