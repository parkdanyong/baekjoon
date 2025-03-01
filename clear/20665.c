/*
    title: 독서실 거리두기
    tag: implement


    Implementation options.
    1. Making a seating chart by time.
    - Let's implement it later.

    2. Loop from 09:00 to 21:00 by one minute and update the seat status.
    - Looks simple then 1st option.

*/




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>




typedef struct TimeCell {
    int start;
    int end;
}tc;


int min (int a, int b) {
    return a < b ? a : b;
}


int compare(const void* arg1, const void* arg2) {
    tc* a = (tc*) arg1;
    tc* b = (tc*) arg2;
    
    int tmp = a->start - b->start;
    if (tmp == 0) return a->end - b->end; // Shorter is preferred
    else return tmp;
}


int parseInt(char* str) {
    int len = strlen(str); // return string length before '\0'.
    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += (str[i] - 48) * pow(10, len - i - 1);
    }
    return sum;
}


int convert2Minutes(int time) {
    return time / 100 * 60 + time % 100;
}


int findSeat(int* seat, int n) {
    /*
        좌석 번호가 작은 순서부터 탐색하고 더 거리가 먼 좌석으로만 업데이트 하기 때문에,
        만일 같은 조건의 좌석이 여러개 나와도 가장 작은 좌석 번호를 유지 가능.
    */
    int low = 0;
    int high = 0;
    int pos = 0;
    int distance = -1;
    int cmp = 0;

    for (int i = 0; i < n; i++) {
        if (seat[i] != 0) continue;
        low = n - 1;
        high = n - 1;

        for (int j = i - 1; j >= 0; j--) { // low
            if (seat[j] != 0) { // in use
                low = i - j - 1;
                break; 
            }
        }
        for (int j = i + 1; j < n; j++) { // high
            if (seat[j] != 0) { // in use
                high = j - i - 1;
                break; 
            }
        }

        cmp = min(low, high);
        if (distance < cmp) {
            pos = i; 
            distance = cmp;
        }
    }


    return pos;
}




int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // int n, t, p;
    // fscanf(file, "%d %d %d", &n, &t, &p);
    // tc* arr = (tc*) malloc(sizeof(tc)*t);
    // char start[5];
    // char end[5];
    // for (int i = 0; i < t; i++) {
    //     fscanf(file, "%4s %4s", start, end);
    //     arr[i].start = convert2Minutes(parseInt(start));
    //     arr[i].end = convert2Minutes(parseInt(end));
    // }   
    // fclose(file);


    // input
    int n, t, p;
    scanf("%d %d %d", &n, &t, &p);
    tc* arr = (tc*) malloc(sizeof(tc)*t);
    char start[5];
    char end[5];
    for (int i = 0; i < t; i++) {
        scanf("%4s %4s", start, end);
        arr[i].start = convert2Minutes(parseInt(start));
        arr[i].end = convert2Minutes(parseInt(end));
    }   


    // init
    qsort(arr, t, sizeof(tc), compare);
    int* seat = (int*) calloc(n, sizeof(int));
    

    // answer
    int ans = 0;
    int reservation = 0;
    for (int m = 540; m < 1260; m++) { // 09:00 ~ 21:00
        // update the timed out seat
        for (int i = 0; i < n; i++) {
            if (seat[i] != 0 && seat[i] <= m) seat[i] = 0;
        }


        // seat the new person
        while (reservation < t && arr[reservation].start == m) {
            if (arr[reservation].start == arr[reservation].end) {
                reservation++;
                continue;
            }
            seat[findSeat(seat, n)] = arr[reservation++].end;
        }
        

        // update ans
        if (seat[p - 1] == 0) ans++;
    }
    printf("%d\n", ans);




    free(arr);
    free(seat);
    return 0;
}