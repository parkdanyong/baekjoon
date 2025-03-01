/*
    title: Z
    tag: divide & conquer



    Let's take a look at the picture in this problem description closely. 
    If you divide the number of visits when n by the value (2^(n-1))^2, you will always get 0, 1, 2, 3 based on the four blocks that make up large Z.
    When n is 2.
    0  1  4  5 
    2  3  6  7
    8  9  12 13
    10 11 14 15

    After dividing by 4. (where 4 is the value of (2^(2-1))^2)
    0 0 1 1
    0 0 1 1
    2 2 3 3
    2 2 3 3

    From outer Z to inner Z in the end it is the same as
    0 1
    2 3

    When n, the number of visits(0, 1, 2, 3) x (2^(n-1))^2 values ​​can be added sequentially from outer Z to inner Z.
  

    Simple instance
    Function dc(n, row, col) return the number of visits.
    When n, row, col values ​​are each 3, 6, 4.


    dc(3, 6, 4) = dc(2, 6 % 2^2, 4 % 2^2) + 3 * (2^3 / 2)^2
    dc(2, 2, 0) = dc(1, 2 % 2^1, 0 % 2^1) + 2 * (2^2 / 2)^2
    dc(1, 0, 0) = 0

    
*/




#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int dc(int n, int row, int col) {
    row %= (int) pow(2, n);
    col %= (int) pow(2, n);
    if (n <= 1) {
        if (row == 0 && col == 0) return 0; 
        else if (row == 0 && col == 1) return 1;
        else if (row == 1 && col == 0) return 2; 
        else return 3;
    }


    int pos;
    int cmp = pow(2, n) / 2;
    if (row < cmp && col < cmp) pos = 0;
    else if (row < cmp && col >= cmp) pos = 1;
    else if (row >= cmp && col < cmp) pos = 2;
    else pos = 3;
    
    int weight = pow(2, n-1);
    int tmp = dc(n-1, row, col) + pos * (int) pow(weight, 2);
    // printf("n: %d pos: %d weight: %d ans: %d\n", n, pos, (int) pow(weight, 2), tmp);
    return tmp;
}



int main() {
    // input
    int n, row, col;
    scanf("%d %d %d", &n, &row, &col);


    // answer
    int ans = dc(n, row, col);
    printf("%d\n", ans);


    return 0;
}