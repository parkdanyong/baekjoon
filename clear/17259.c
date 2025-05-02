/*
    title: 선물이 넘쳐흘러
    tag: implement
*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Employee {
    int pos;
    int time;
    int state;
}Employee;


int B, N, P, size;
int* arr;
Employee* employees;


int move(int push) {
    int left = 0;

    for (int i = B*(B-1) + 1; i < size; i++) {
        if (arr[i] == 1) left = 1;
        arr[i-1] = arr[i];
    }
    for (int i = B*(B-1) - 1; i >= 0; i -= B) {
        if (arr[i] == 1) left = 1;
        arr[i+B] = arr[i];
    }
    for (int i = B-2; i >= 0; i--) {
        if (arr[i] == 1) left = 1;
        arr[i+1] = arr[i];
    }
    if (push == 1) {
        left = 1;
        arr[0] = 1;
    }
    else arr[0] = 0;
    return left;
}


int solve() {
    int present = P;
    int flag;
    int count = 0;
    while (1) {
        if (present != 0) {
            present -= 1;
            flag = move(1);
        }
        else flag = move(0);
        if (flag == 0) break;

        for (int i = 0; i < N; i++) {
            if (employees[i].state > 0) employees[i].state -= 1;
            if (employees[i].state == 0) {
                if (arr[employees[i].pos + B] == 1) {
                    arr[employees[i].pos + B] = 0;
                    employees[i].state = employees[i].time;
                    count += 1;
                }
                else if (arr[employees[i].pos + 1] == 1) {
                    arr[employees[i].pos + 1] = 0;
                    employees[i].state = employees[i].time;
                    count += 1;
                }
                else if (arr[employees[i].pos - B] == 1) {
                    arr[employees[i].pos - B] = 0;
                    employees[i].state = employees[i].time;
                    count += 1;
                }
            }


            // for (int i = 0; i < size; i++) {
            //     printf("%d ", arr[i]);
            //     if ((i+1)%B == 0) printf("\n");
            // }
            // printf("\n");
        }
    }
    return count;
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d %d", &B, &N, &P);
    // size = B * B;
    // arr = (int*) calloc(size, sizeof(int));
    // employees = (Employee*) malloc(sizeof(Employee)*N);
    // int row, col, t;
    // for (int i = 0; i < N; i++) {
    //     fscanf(file, "%d %d %d", &row, &col, &t);
    //     employees[i].pos = B*row + col;
    //     employees[i].time = t;
    //     employees[i].state = 0;
    // }
    // fclose(file);


    // input
    scanf("%d %d %d", &B, &N, &P);
    size = B * B;
    arr = (int*) calloc(size, sizeof(int));
    employees = (Employee*) malloc(sizeof(Employee)*N);
    int row, col, t;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &row, &col, &t);
        employees[i].pos = B*row + col;
        employees[i].time = t;
        employees[i].state = 0;
    }



    // answer
    int ans = solve();
    printf("%d\n", ans);


    free(arr);
    free(employees);
    return 0;
}