/*
    title: 모두싸인 출근길
    tag: implement


    Unify overlapping boards into one.

*/




#include <stdio.h>
#include <stdlib.h>



typedef struct Board {
    int start;
    int end;
}board;


int compare(const void* a, const void* b) {
    board a_board = *(const board*) a;
    board b_board = *(const board*) b;

    return a_board.start - b_board.start;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}


// int jumpBoard(board* b, int length, int cur) {
//     /*
//         예제 입력 2번과 같은 상황
//         도달할 수 있는 판자가 여러개 일 경우, 선택한 판자에 따라서 최종 도달 위치가 달라질 수 있다.
//         이러한 판자 선택이 연속해서 나올 경우도 대비해야 한다.
//     */
    

//     int position = b[cur].end; // 현재 위치
//     int reach = b[cur].end * 2 - b[cur].start; // 최대 점프 가능 위치
//     if (reach == b[length - 1].end) return reach; // 종점과 맞닿아 있다면 return


//     int tmp = 0;
//     for (int i = cur + 1; i < length; i++) {
//         if (reach < b[i].start) break; // 더 이상 점프 불가능

//         tmp = jumpBoard(b, length, i); 
//         if (position < tmp) position = tmp;
//     }

//     return position;
// }



int main() {
    // input 
    // FILE* file = fopen("inputFile.txt", "r");
    // int count = 0;
    // fscanf(file, "%d", &count);
    // board* boards = (board*) malloc(sizeof(board)*count);
    // for (int i = 0; i < count; i++) {
    //     fscanf(file, "%d %d", &boards[i].start, &boards[i].end);
    // }
    // fclose(file);


    int count = 0;
    scanf("%d", &count);
    board* boards = (board*) malloc(sizeof(board)*count);
    for (int i = 0; i < count; i++) {
        scanf("%d %d", &boards[i].start, &boards[i].end);
    }




    // init
    // board sorting
    qsort(boards, count, sizeof(board), compare);
    
    // unify boards
    board* unifiedBoards = (board*) malloc(sizeof(board)*count);
    unifiedBoards[0].start = boards[0].start;
    unifiedBoards[0].end = boards[0].end;
    int length = 1;
    for (int i = 1; i < count; i++) {
        if (boards[i].start <= unifiedBoards[length-1].end) { // 겹친다.
            unifiedBoards[length-1].end = max(boards[i].end, unifiedBoards[length-1].end);
        }
        else { // 안 겹치면 새로운 판자자
            length++;
            unifiedBoards[length-1].start = boards[i].start;
            unifiedBoards[length-1].end = boards[i].end;
        }
    }



    
    // output
    // printf("%d\n", jumpBoard(unifiedBoards, length, 0));

    int position = unifiedBoards[0].end; // 최대 이동 거리
    int reach = position * 2; // 이전 판자의 reach
    int cur = 0; // 현재 판자의 reach
    for (int i = 1; i < length; i++) { 
        cur = unifiedBoards[i].end * 2 - unifiedBoards[i].start;
        if (reach < unifiedBoards[i].start) break; // 이전의 판자에서 도달 가능?
        
        position = unifiedBoards[i].end; // 도달 가능하면 일단 최대 이동 거리는 update
        reach = max(reach, cur); // reach는 점프 가능한 최대 범위를 가지고 있어야 한다.
        /*
            reach와 최대 이동 거리를 독립적으로 업데이트 하는 이유는 다음과 같다.
            예제 2번의 경우에서 만일 (19, 20) 판자 위치가, (20, ?) 이라고 한다면, (11, 15), (16, 17) 판자에서 점프하지 못 한다. 
            결국 최대 이동 거리는 17이다.
            즉, (16, 17) 판자의 reach가 더 짧아도 최대 이동 거리는 17로 업데이트를 반드시 해야한다.
            (16, 17) 판자에 임시로 스폰 지역을 만들고, 가장 긴 reach로도 다음 판자에 도달하지 못하면 여기로 스폰한다고 생각하자.
        */
    }
    printf("%d\n", position);



    free(boards);
    free(unifiedBoards);

    return 0;
}