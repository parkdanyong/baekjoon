/*
    title: 잃어버린 괄호
    tag: math, greedy algorithm, string, parsing


    Enclose the numbers between - and - in parentheses.
    
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* string;


int main() {
    // FILE* file = fopen("inputFile.txt", "r");
    // string str = (string) malloc(sizeof(char)*100);
    // fscanf(file, "%s", str);
    // fclose(file);


    // input
    string str = (string) malloc(sizeof(char)*100);
    scanf("%s", str);


    // init
    int len = strlen(str);
    char tmp[100]; 
    strcpy(tmp, str);
    string token = (string) malloc(sizeof(char)*10);
    token = strtok(tmp, "+-");
    int op = 0;
    int mem = 0;
    int flag = 0;

    
    // answer
    int ans = atoi(token);
    while (1) {
        token = strtok(NULL, "+-");
        if (token == NULL) break;


        for (; op < len; op++) {
            if (str[op] == '-') {
                flag = 1;
                ans -= mem;
                mem = 0;
                break;
            }
            else if (str[op] == '+') break;
        }
        op += 1;
        if (flag) mem += atoi(token);
        else ans += atoi(token);
    }
    ans -= mem;
    printf("%d\n", ans);



    free(str);
    free(token);
    return 0;
}