/*
    LCS: Longest Common Subsequence


    dp
    O(n*m)

    
*/


int max(int a, int b) {
    return a > b ? a : b;
}


void LCS(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int* arr = (int*) calloc((len1+1)*(len2+1), sizeof(int));

    int i = 0, j = 0;
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) arr[(len2+1)*i + j] = arr[(len2+1)*(i-1) + (j-1)] + 1;
            else arr[(len2+1)*i + j] = max(arr[(len2+1)*(i-1) + j], arr[(len2+1)*i + (j-1)]);
        }
    }


    int len = arr[(len2+1)*len1 + len2];
    char* lcs = (char*) malloc(sizeof(char)*(len+1));
    lcs[len] = '\0';
    i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) { 
            lcs[len - 1] = str1[i - 1];
            i--;
            j--;
            len--;
        } else if (arr[(len2+1)*(i-1) + j] > arr[(len2+1)*i + (j-1)]) i--;
        else j--;
    }
    free(arr);
    free(lcs);
}

