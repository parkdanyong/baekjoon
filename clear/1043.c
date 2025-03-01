/*
    title: 거짓말
    tag: graph, Disjoint Set
*/



#include <stdio.h>
#include <stdlib.h>


#define MAX_SIZE 2550


typedef struct Node {
    int parent;
    int knowing;
}node;


int n, m;
node* arr;
int* party;



int findSets(int node) {
    while (1) {
        if (arr[node].parent == 0) break;
        node = arr[node].parent;
    }
    return node;
}


void unionSets(int n1, int n2) {
    int n1_root = findSets(n1);
    int n2_root = findSets(n2);
    if (n1_root == n2_root) return;
    
    if (arr[n1_root].knowing == 1) {
        arr[n2_root].parent = n1;
    }
    else if (arr[n2_root].knowing == 1) {
        arr[n1_root].parent = n2;
    }
    else {
        arr[n1_root].parent = n2;
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // int person;
    // int count;
    // arr = (node*) calloc(n+1, sizeof(node));
    // fscanf(file, "%d", &count);
    // for (int i = 0; i < count; i++) {
    //     fscanf(file, "%d", &person);
    //     arr[person].knowing = 1;
    // }
    // party = (int*) malloc(sizeof(int)*MAX_SIZE);
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d", &count);
    //     party[51*i] = count;
    //     for (int j = 1; j <= count; j++) {
    //         fscanf(file, "%d", &party[51*i + j]);
    //     }
    // }
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    int person;
    int count;
    arr = (node*) calloc(n+1, sizeof(node));
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &person);
        arr[person].knowing = 1;
    }
    party = (int*) malloc(sizeof(int)*MAX_SIZE);
    for (int i = 0; i < m; i++) {
        scanf("%d", &count);
        party[51*i] = count;
        for (int j = 1; j <= count; j++) {
            scanf("%d", &party[51*i + j]);
        }
    }


    // init 
    for (int i = 0; i < m; i++) {
        for (int j = 2; j <= party[51*i]; j++) {
            unionSets(party[51*i + j - 1], party[51*i + j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        // printf("node: %d parent: %d: knowing: %d\n", i, findSets(i), arr[findSets(i)].knowing);
        if (arr[findSets(i)].knowing == 1) {
            arr[i].knowing = 1;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("num: %2d knowing: %d\n", i, arr[i].knowing);
    // }
    

    // answer
    int ans = m;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= party[51*i]; j++) {
            if (arr[party[51*i + j]].knowing == 1) {
                ans -= 1;
                break;
            }
        }
    }
    printf("%d\n", ans);


    free(arr);
    free(party);
    return 0;
}