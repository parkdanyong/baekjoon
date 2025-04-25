/*
    title: 명령 프롬프트
    tag: 
*/



#include <stdio.h>
#include <string.h>


#define MAX_STRING_LEN 100


int main() {
    // input
    char standard[MAX_STRING_LEN];
    char cmp[MAX_STRING_LEN];
    int n;
    scanf("%d", &n);
    scanf("%s", standard);
    int len = strlen(standard);
    for (int i = 1; i < n; i++) {
        scanf("%s", cmp);
        for (int i = 0; i < len; i++) {
            if (standard[i] != cmp[i]) standard[i] = '?';
        }
    }

    
    printf("%s\n", standard);
    return 0;
}