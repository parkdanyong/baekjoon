/*
    title: 
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



int main() {
    // 변수 -> 부호 + 변수 확인
    // 16진수 -> 부호 없으니까 범위만 확인
    // 10진수 상수 -> 부호 + 범위 확인
    printf("%d %hd\n", 0x8000, 3+USHRT_MAX);
    printf("%hd\n", CHAR_MIN);


    

    return 0;
}