/*
    title: 단어 정렬
    tag: string, sorting
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int compare(const void* arg1, const void* arg2) {
    char* a = *(char**) arg1;
    char* b = *(char**) arg2;


    int cmp = strlen(a) - strlen(b);
    if (cmp != 0) return cmp;
    
    return strcmp(a, b);
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n;
    // fscanf(file, "%d", &n);
    // char** arr = (char**) malloc(sizeof(char*)*n); 
    // for (int i = 0; i < n; i++) {
    //     arr[i] = (char*) malloc(sizeof(char)*51);
    //     fscanf(file, "%s", arr[i]);
    // }
    // fclose(file);


    // input
    int n;
    scanf("%d", &n);
    char** arr = (char**) malloc(sizeof(char*)*n); 
    for (int i = 0; i < n; i++) {
        arr[i] = (char*) malloc(sizeof(char)*51);
        scanf("%s", arr[i]);
    }


    // init
    qsort(arr, n, sizeof(char*), compare);



    // answer
    int pre = 0; 
    printf("%s\n", arr[pre]);
    for (int i = 1; i < n; i++) {
        if (strcmp(arr[i], arr[pre]) != 0) printf("%s\n", arr[i]);
        pre = i;
    }



    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}

