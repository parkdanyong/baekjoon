/*
    title: 나이순 정렬
    tag: sorting
*/



#include <stdio.h>
#include <stdlib.h>



typedef char* str;
typedef struct Member {
    str name;
    int age;
    int priority;
}member;


int compare(const void* arg1, const void* arg2) {
    member* a = (member*) arg1;
    member* b = (member*) arg2;

    int cmp = a->age - b->age;
    if (cmp == 0) cmp = a->priority - b->priority;
    return cmp;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n = 0;
    // fscanf(file, "%d", &n);
    // member* arr = (member*) malloc(sizeof(member)*n);
    // for (int i = 0; i < n; i++) {
    //     arr[i].name = (str) malloc(sizeof(char)*101);
    //     fscanf(file, "%d %s", &arr[i].age, arr[i].name);
    //     arr[i].priority = i;
    // }
    // fclose(file);


    // input
    int n = 0;
    scanf("%d", &n);
    member* arr = (member*) malloc(sizeof(member)*n);
    for (int i = 0; i < n; i++) {
        arr[i].name = (str) malloc(sizeof(char)*101);
        scanf("%d %s", &arr[i].age, arr[i].name);
        arr[i].priority = i;
    }


    // init
    qsort(arr, n, sizeof(member), compare);


    // answer
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", arr[i].age, arr[i].name);
    }


    for (int i = 0; i < n; i++) {
        free(arr[i].name);
    }
    free(arr);
    return 0;
}