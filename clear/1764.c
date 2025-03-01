/*
    title: 듣보잡
    tag: string, sorting set/map using hash
*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* string;


int compare(const void* arg1, const void* arg2) {
    string a = *(string*) arg1;
    string b = *(string*) arg2;

    return strcmp(a, b);
}


int compare2(const void* arg1, const void* arg2) {
    return *(int*) arg1 - *(int*) arg2;
}


int binarySearch(string* set, int size, string str) {
    int left = 0;
    int right = size - 1;
    int mid = 0;

    int cmp = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;

        cmp = strcmp(set[mid], str);
        if (cmp < 0) left = mid + 1;
        else if (cmp > 0) right = mid - 1;
        else return mid;
    }

    return -1;
}


int main() {
    // input
    int n, m;
    scanf("%d %d", &n, &m);
    string* set = (string*) malloc(sizeof(string)*n);
    for (int i = 0; i < n; i++) {
        set[i] = (string) malloc(sizeof(char)*21);
        scanf("%s", set[i]);
    }

    
    // init
    qsort(set, n, sizeof(string), compare);
    string str = (string) malloc(sizeof(char)*21);    


    // answer
    int* ans = (int*) malloc(sizeof(int)*n);
    int size = 0;
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        scanf("%s", str);
        tmp = binarySearch(set, n, str);
        if (tmp != -1) ans[size++] = tmp;
    }

    qsort(ans, size, sizeof(int), compare2);
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%s\n", set[ans[i]]);
    }




    for (int i = 0; i < n; i++) {
        free(set[i]);
    }
    free(set);
    free(str);
    free(ans);
    return 0;
}