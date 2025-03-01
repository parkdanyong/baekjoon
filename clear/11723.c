/*
    title: 집합
    tag: set, bitmasking
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* str;


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // str command = (str) malloc(sizeof(char)*10);
    // int data;
    // int* set = (int*) calloc(21, sizeof(int));
    // for (int i = 0; i < n; i++) {
    //     fscanf(file, "%s %d", command, &data);
    //     // printf("%s\n", command);
    //     if (strcmp(command, "add") == 0) set[data] = 1;
    //     else if (strcmp(command, "remove") == 0) set[data] = 0;
    //     else if (strcmp(command, "check") == 0) printf("%d\n", set[data]);
    //     else if (strcmp(command, "toggle") == 0) {
    //         if (set[data] == 0) set[data] = 1;
    //         else set[data] = 0;
    //     }
    //     else if (strcmp(command, "all") == 0) {
    //         for (int i = 1; i < 21; i++) {
    //             set[i] = 1;
    //         }
    //     }
    //     else if (strcmp(command, "empty") == 0) {
    //         for (int i = 1; i < 21; i++) {
    //             set[i] = 0;
    //         }
    //     }
    // }
    // fclose(file);


    // input 
    int n;
    scanf("%d", &n);
    str command = (str) malloc(sizeof(char)*10);
    int data;
    int* set = (int*) calloc(21, sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%s %d", command, &data);
        // printf("%s\n", command);
        if (strcmp(command, "add") == 0) set[data] = 1;
        else if (strcmp(command, "remove") == 0) set[data] = 0;
        else if (strcmp(command, "check") == 0) printf("%d\n", set[data]);
        else if (strcmp(command, "toggle") == 0) {
            if (set[data] == 0) set[data] = 1;
            else set[data] = 0;
        }
        else if (strcmp(command, "all") == 0) {
            for (int i = 1; i < 21; i++) {
                set[i] = 1;
            }
        }
        else if (strcmp(command, "empty") == 0) {
            for (int i = 1; i < 21; i++) {
                set[i] = 0;
            }
        }
    }



    free(command);
    free(set);
    return 0;
}