/*
    title: 팝핀 소다
    tag: math

*/



#include <stdio.h>
#include <math.h>



int main() {
    int n, fate, ability;
    scanf("%d %d %d", &n, &fate, &ability);

    int maxBattle = log2(n);
    int canWin = log2(ability) + fate;
    printf("%d\n", canWin < maxBattle ? canWin : maxBattle); 


    return 0;
}