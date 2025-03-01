/*
    title: 팰린드롬?
    tag: dp

    
    다른 일반적인 solution
    길이가 1일 때: O
    길이가 2일 때: 양 끝이 같다면 O
    길이가 3이 이상일 때: 양 끝이 같고 내부가 팰린드롬이면 O
    
*/



#include <stdio.h>
#include <stdlib.h>


int n, m;
int* arr;
int size;
int* p_matrix;


void palindrome() {
    for (int i = 0; i < size; i++) {
        p_matrix[i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[i] == arr[j]) p_matrix[(n+1)*i + j] = p_matrix[(n+1)*(i-1) + (j+1)];
            else p_matrix[(n+1)*i + j] = 0;
        }
    }
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d", &n);
    // arr = (int*) malloc(sizeof(int)*(n+1));
    // arr[0] = 0;
    // for (int i = 1; i <= n; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // size = (n+1) * (n+1);
    // p_matrix = (int*) malloc(sizeof(int)*size);
    // palindrome();
    // fscanf(file, "%d", &m);
    // int v1, v2;
    // for (int i = 0; i < m; i++) {
    //     fscanf(file, "%d %d", &v1, &v2);
    //     printf("%d\n", p_matrix[(n+1)*v2 + v1]);
    // }
    // fclose(file);


    // input
    scanf("%d", &n);
    arr = (int*) malloc(sizeof(int)*(n+1));
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }


    // init
    size = (n+1) * (n+1);
    p_matrix = (int*) malloc(sizeof(int)*size);


    // answer
    palindrome();
    scanf("%d", &m);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &v1, &v2);
        printf("%d\n", p_matrix[(n+1)*v2 + v1]);
    }


    free(arr);
    free(p_matrix);
    return 0;
}