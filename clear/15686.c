/*
    title: 치킨 배달
    tag: brute force, backTracking


    
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define MAX_CHICKEN 13
#define INF 10000


typedef struct Point {
    int row;
    int col;
}point;


int n, m, size;
point* house;
point* chicken;
int houseCount;
int chickenCount;
int* dis;
int* choice;


int min(int a, int b) {
    return a < b ? a : b;
}


int backTrack(int count) {
    if (count > m) {
        int cmp = 0;
        int minVal = INF;
        for (int i = 0; i < houseCount; i++) {
            for (int j = 1; j <= m; j++) {
                minVal = min(minVal, dis[chickenCount*i + choice[j]]);
            }
            cmp += minVal;
            minVal = INF;
        }
        return cmp;
    }


    int val = INF;
    for (int i = choice[count - 1] + 1; i < chickenCount; i++) {
        choice[count] = i;
        val = min(val, backTrack(count + 1));
    }
    return val;
}


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // fscanf(file, "%d %d", &n, &m);
    // size = n*n;
    // house = (point*) malloc(sizeof(point)*2*n);
    // chicken = (point*) malloc(sizeof(point)*MAX_CHICKEN);
    // houseCount = 0;
    // chickenCount = 0;
    // int tmp;
    // for (int i = 0; i < size; i++) {
    //     fscanf(file, "%d", &tmp);
    //     if (tmp == 1) { // house
    //         house[houseCount].row = i / n + 1;
    //         house[houseCount].col = i % n + 1;
    //         houseCount += 1;
    //     }
    //     else if (tmp == 2) { // chicken
    //         chicken[chickenCount].row = i / n + 1;
    //         chicken[chickenCount].col = i % n + 1;
    //         chickenCount += 1;
    //     }
    // }    
    // fclose(file);


    // input
    scanf("%d %d", &n, &m);
    size = n*n;
    house = (point*) malloc(sizeof(point)*2*n);
    chicken = (point*) malloc(sizeof(point)*MAX_CHICKEN);
    houseCount = 0;
    chickenCount = 0;
    int tmp;
    for (int i = 0; i < size; i++) {
        scanf("%d", &tmp);
        if (tmp == 1) { // house
            house[houseCount].row = i / n + 1;
            house[houseCount].col = i % n + 1;
            houseCount += 1;
        }
        else if (tmp == 2) { // chicken
            chicken[chickenCount].row = i / n + 1;
            chicken[chickenCount].col = i % n + 1;
            chickenCount += 1;
        }
    }


    // init
    dis = (int*) malloc(sizeof(int)*houseCount*chickenCount);
    for (int i = 0; i < houseCount; i++) {
        for (int j = 0; j < chickenCount; j++) {
            dis[chickenCount*i + j] = abs(house[i].row - chicken[j].row) + abs(house[i].col - chicken[j].col);
        }
    }
    choice = (int*) malloc(sizeof(int)*(m+1));
    choice[0] = -1;


    // answer
    int ans = backTrack(1);
    printf("%d\n", ans);


    free(house);
    free(chicken);
    free(dis);
    free(choice);
    return 0;
}