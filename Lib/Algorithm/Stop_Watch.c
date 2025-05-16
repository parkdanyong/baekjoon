#include <time.h>


int main() {
    clock_t start = clock();
    clock_t end = clock();
    printf("%.10lf", (double)(end - start) / CLOCKS_PER_SEC); // second 단위


    return 0;
}