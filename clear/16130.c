/*
    title: 벌점 (DemeritPoints)
    tag: math
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>






int main() {
    int T;
    scanf("%d", &T);
    char str[50];
    int flag;
    int ans;
    int sum;
    int cur;
    int len;
    for (int t = 0; t < T; t++) {
        scanf("%s", str);
        len = strlen(str);
        sum = 0;
        ans = 0;
        flag = 1;
        for (int i = 0; i < len; i++) {
            if (str[i] < 'A') cur = str[i] - '0';
            else cur = str[i] - 'A' + 10;

            if (sum / 10 != (sum + cur) / 10) {
                sum += cur;
                if (5 <= sum / 10) {
                    printf("%d(09)\n", ans);
                    flag = 0;
                    break;
                }
                else if (4 <= sum / 10) {
                    printf("%d(weapon)\n", ans);
                    flag = 0;
                    break;
                }
                ans += sum / 10;
            }
            else sum += cur;
        }
        if (flag) printf("%d\n", ans);
    }



    return 0;
}