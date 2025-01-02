#include <stdio.h>


int main() {
    int n = 0;
    scanf("%d", &n);

    int b = (n - 1) % 3;
    if (b == 0) printf("U\n");
    else if (b == 1) printf("O\n");
    else if (b == 2) printf("S\n");

    return 0;
}