/*
    title: ZOAC
    tag: implement, string, recursion
    
    The string's maximum length is 100.
    This means we can use O(n^2) algorithm on this problem.
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void findPriority(char* str, int* activated, int len, int left, int right) {
    /*
        If the size of the array is n, the number of recursive calls is n.
        Total O(n^2).
    */

    if (left > right) return;

    int pri = left;
    for (int i = left + 1; i <= right; i++) { 
        if (str[i] < str[pri]) pri = i;
    }
    activated[pri] = 1;
    for (int i = 0; i < len; i++) { // O(n)
        if (activated[i] == 1) printf("%c", str[i]);
    }
    printf("\n");

    findPriority(str, activated, len, pri + 1, right); 
    findPriority(str, activated, len, left, pri - 1); 
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*101);
    // fscanf(file, "%s", str);
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*101);
    scanf("%s", str);

    
    // init
    int len = strlen(str);
    int* activated = (int*) calloc(len, sizeof(int));


    // answer
    findPriority(str, activated, len, 0, len - 1);
    


    free(str);
    free(activated);
    return 0;
}