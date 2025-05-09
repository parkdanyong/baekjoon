/*
    title: Access Denied
    tag: 
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define RESPONSE_LEN 100
#define MAX_STR_LEN 30
#define TYPES 62



char type[TYPES];
char ans[MAX_STR_LEN];
int len;


void init() {
    char c = '0';
    for (int i = 0; i < 10; i++) {
        type[i] = c;
        c += 1;
    }
    c = 'A';
    for (int i = 10; i < 36; i++) {
        type[i] = c;
        c += 1;
    }
    c = 'a';
    for (int i = 36; i < 62; i++) {
        type[i] = c;
        c += 1;
    }
}


void add(char c) {
    ans[len] = c;
    len += 1;
    ans[len] = '\0';
}


void changeChar(int index) {
    char c = ans[index];
    int to;
    if (c < 'A') to = c - '0';
    else if (c < 'a') to = c - 'A' + 10;
    else to = c - 'a' + 36;
    ans[index] = type[to+1];
}


int main() {
    // answer
    init();
    len = 0;
    add('0');


    char response[RESPONSE_LEN];
    char* token;
    int val;
    while (1) {
        printf("%s\n", ans);
        fflush(stdout);

        fgets(response, RESPONSE_LEN, stdin);
        if (strstr(response, "GRANTED")) break;
        token = strtok(response, " ");
        token = strtok(NULL, " ");
        
        
        token = strtok(NULL, " ") + 1;
        val = atoi(token);
        if (val == 5) add('0');
        else {
            val = (int) (val - 14) / 9;
            changeChar(val);
        }
    }


    return 0;
}