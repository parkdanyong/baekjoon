/*
    title: 테트로미노
    tag: implement, brute force
*/



#include <stdio.h>
#include <stdlib.h>


int rows, cols;
int size;
int* arr;


int max(int a, int b) {
    return a > b ? a : b;
}


int square(int pos) {
    int maxSum = 0;
    if (pos % cols + 1 < cols && pos + cols + 1 < size) {
        maxSum += arr[pos];
        maxSum += arr[pos + 1];
        maxSum += arr[pos + cols];
        maxSum += arr[pos + cols + 1];
    }
    return maxSum;
}


int straight(int pos) {
    int maxSum = 0;
    int cmp = 0;
    if (pos % cols + 3 < cols) {
        for (int i = 0; i < 4; i++) {
            cmp += arr[pos + i];
        }
        maxSum = max(maxSum, cmp);
        cmp = 0;
    }
    if (pos + 3 * cols < size) {
        for (int i = 0; i < 4; i++) {
            cmp += arr[pos + i * cols];
        }
        maxSum = max(maxSum, cmp);
        cmp = 0;
    }
    return maxSum;
}


int stair(int pos) {
    int maxSum = 0;
    int cmp = 0;
    if (pos % cols + 1 < cols && pos + cols < size) {
        if (0 <= pos % cols - 1) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + cols];
            cmp += arr[pos + cols - 1];
            maxSum = max(maxSum, cmp);
        }
        if (pos % cols + 2 < cols) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + cols + 1];
            cmp += arr[pos + cols + 2];
            maxSum = max(maxSum, cmp);
        }   
        if (pos + 2 * cols < size) {
            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + cols + 1];
            cmp += arr[pos + 2 * cols + 1];
            maxSum = max(maxSum, cmp);

            if (0 <= pos % cols - 1) {
                cmp = arr[pos];
                cmp += arr[pos + cols];
                cmp += arr[pos + cols - 1];
                cmp += arr[pos + 2 * cols - 1];
                maxSum = max(maxSum, cmp);
            }
        }
    }
    return maxSum;
}


int fword(int pos) {
    int maxSum = 0;
    int cmp = 0;
    if (pos % cols + 2 < cols) {
        if (0 <= pos - cols) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos - cols + 1];
            maxSum = max(maxSum, cmp);
        }
        if (pos + cols < size) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos + cols + 1];
            maxSum = max(maxSum, cmp);
        }
    }
    if (pos + 2 * cols < size) {
        if (0 <= pos % cols - 1) {
            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos + cols - 1];
            maxSum = max(maxSum, cmp);
        }
        if (pos % cols + 1 < cols) {
            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos + cols + 1];
            maxSum = max(maxSum, cmp);
        }
    }
    return maxSum;
}


int foot(int pos) {
    int maxSum = 0;
    int cmp = 0;
    if (pos % cols + 2 < cols) {
        if (0 <= pos - cols) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos - cols];
            maxSum = max(maxSum, cmp);

            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos - cols + 2];
            maxSum = max(maxSum, cmp);
        }
        if (pos + cols < size) {
            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos + cols];
            maxSum = max(maxSum, cmp);

            cmp = arr[pos];
            cmp += arr[pos + 1];
            cmp += arr[pos + 2];
            cmp += arr[pos + cols + 2];
            maxSum = max(maxSum, cmp);
        }
    }
    if (pos + 2 * cols < size) {
        if (0 <= pos % cols - 1) {
            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos - 1];
            maxSum = max(maxSum, cmp);

            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos + 2 * cols - 1];
            maxSum = max(maxSum, cmp);
        }
        if (pos % cols + 1 < cols) {
            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos + 1];
            maxSum = max(maxSum, cmp);

            cmp = arr[pos];
            cmp += arr[pos + cols];
            cmp += arr[pos + 2 * cols];
            cmp += arr[pos + 2 * cols + 1];
            maxSum = max(maxSum, cmp);
        }
    }
    return maxSum;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &rows, &cols);
    // size = rows * cols;
    // arr = (int*) malloc(sizeof(int)*size);
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &arr[i]);
    // }
    // fclose(file);


    // input
    scanf("%d %d", &rows, &cols);
    size = rows * cols;
    arr = (int*) malloc(sizeof(int)*size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    
    // answer
    int ans = 0;
    for (int i = 0; i < size; i++) {
        ans = max(ans, square(i));
        ans = max(ans, straight(i));
        ans = max(ans, stair(i));
        ans = max(ans, fword(i));
        ans = max(ans, foot(i));
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}