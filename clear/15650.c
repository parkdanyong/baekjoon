/*
    title: N과 M (2)
    tag: backtracking


    1 
    1 2
    1 2 3
    ...
    1 2 n
    1 3
    1 3 1
    ...

*/



#include <stdio.h>
#include <stdlib.h>


int n, m;
int* ans;


void backtrack(int index, int start) {
    if (index == m) { // find sequence
        for (int i = 0; i < index; i++) {
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }


    for (int i = start; i <= n; i++) {
        ans[index] = i;
        backtrack(index + 1, i + 1);
    }
}



int main() {
    // input
    scanf("%d %d", &n, &m);


    // answer
    ans = (int*) malloc(sizeof(int)*m);
    backtrack(0, 1);



    
    free(ans);
    return 0;
}



