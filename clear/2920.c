/*
    title: 음계
    tag: implement
*/


#include <stdio.h>


int main() {
    // input
    int n;
    int ascending = 1, descending = 8;
    for (int i = 0; i < 8; i++) {
        scanf("%d", &n);
        if (n == ascending) ascending += 1;
        if (n == descending) descending -= 1;
    }


    // answer
    if (ascending == 9) printf("ascending\n");
    else if (descending == 0) printf("descending\n");
    else printf("mixed\n");
}