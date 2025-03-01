/*
    title: FizzBuzz
    tag: math, string


    1 2 (3) 4 (5) (6) 7 8 (9) (10) 11 (12) 13 14 (15) 16 17 (18) 19 (20) (21)
    3 * 5 
   

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isInteger(const char* str) {
    char* endptr;
    strtol(str, &endptr, 10);

    return *str != '\0' && *endptr == '\0';
}



int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // char* str = (char*) malloc(sizeof(char)*10);
    // int n;
    // for (int i = 1; i <= 3; i++) {
    //     fscanf(file, "%s", str);
    //     if (isInteger(str)) {
    //         n = atoi(str) + 1 + (3 - i);
    //         break;
    //     }
    // }
    // fclose(file);


    // input
    char* str = (char*) malloc(sizeof(char)*10);
    int n;
    for (int i = 1; i <= 3; i++) {
        scanf("%s", str);
        if (isInteger(str)) {
            n = atoi(str) + 1 + (3 - i);
            break;
        }
    }


    // answer
    if (n % 15 == 0) printf("FizzBuzz\n");
    else if (n % 3 == 0) printf("Fizz");
    else if (n % 5 == 0) printf("Buzz\n");
    else printf("%d\n", n);


    free(str);
    return 0;
}