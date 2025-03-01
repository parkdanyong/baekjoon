/*
    Vector

    append: O(1)
    insert: O(n)
    delete: O(1)
    
*/


#include <stdlib.h>


typedef struct Vector {
    int* arr;
    int len;
    int capacity;
}vector;


vector* createVector(int capacity) {
    vector* vec = (vector*) malloc(sizeof(vector));
    vec->arr = (int*) malloc(sizeof(int)*capacity);
    vec->len = 0;
    vec->capacity = capacity;
    return vec;
}


void resize(vector* vec) {
    vec->capacity *= 2;
    vec->arr = (int*) realloc(vec->arr, sizeof(int)*vec->capacity);
}


void append(vector* vec, int val) {
    if (vec->len == vec->capacity) resize(vec);
    vec->arr[vec->len++] = val;
}


int delete(vector* vec) {
    if (vec->len == 0) return -1;
    return vec->arr[--vec->len];
}


void freeVector(vector *vec) {
    free(vec->arr);
    free(vec);
}