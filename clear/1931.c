/*
    title: 회의실 배정
    tag: greedy algorithm, sotring


    Solution.
    1. Sort by end time. If the same, sort by start time. (ascending order)
    2. Starting index 0, non-overlapped meetings are stored in array. (you can just store the index of sorted meetings array)


    Simple instance. (after sorting)

    1 4 
    3 5 
    0 6
    5 7 
    3 8
    5 9
    6 10
    8 11 
    8 12
    2 13
    12 14

    The 1st meeting always can use.
    store: (1, 4)

    (3, 5) -> overlapped with stored: (1, 4)
    (0, 6) -> overlapped with stored: (1, 4)
    (5, 7) -> non-overlapped, store: (1, 4), (5, 7)
    (3, 8) -> overlapped with stored: (1, 4), (5, 7)
    (6, 10) -> overlapped with stored: (1, 4), (5, 7)
    (8, 11) -> non-overlapped, store: (1, 4), (5, 7), (8, 11)
    (8, 12) -> overlapped with stored: (1, 4), (5, 7), (8, 11)
    (2, 13) -> overlapped with stored: (1, 4), (5, 7), (8, 11)
    (12, 14) -> non-overlapped, store: (1, 4), (5, 7), (8, 11), (12, 14)

    Finally (1, 4), (5, 7), (8, 11), (12, 14) those meetings can use.

*/



#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int start;
    int end;
}node;


int compare(const void* arg1, const void* arg2) {
    node* a = (node*) arg1;
    node* b = (node*) arg2;

    int cmp = a->end - b->end;
    if (cmp != 0) return cmp;
    else return a->start - b->start;
}


int main() {
    FILE* file = fopen("inputFile.txt", "r");
    int n;
    fscanf(file, "%d", &n);
    node* arr = (node*) malloc(sizeof(node)*n); // start, end
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &arr[i].start, &arr[i].end);
    }
    fclose(file);


    // input
    // int n;
    // scanf("%d", &n);
    // node* arr = (node*) malloc(sizeof(node)*n); // start, end
    // for (int i = 0; i < n; i++) {
    //     scanf("%d %d", &arr[i].start, &arr[i].end);
    // }


    // init
    // sort arr
    qsort(arr, n, sizeof(node), compare);
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", arr[i].start, arr[i].end);
    // }

    
    // answer
    int lastMeeting = 0;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (arr[lastMeeting].end <= arr[i].start) {
            lastMeeting = i;
            ans += 1;
        }
    }
    printf("%d\n", ans);


    free(arr);
    return 0;
}