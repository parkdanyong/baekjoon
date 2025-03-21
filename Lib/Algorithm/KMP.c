/*
    KMP
    
*/


void computeLPSArray(char* pattern, int n, int* lps) {
    int len = 0; 
    lps[0] = 0; 
    int i = 1; 

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int KMP(char* str, char* pattern) {
    int n = strlen(str);
    int m = strlen(pattern);

    int lps[m];
    computeLPSArray(pattern, m, lps);

    int i = 0;  
    int j = 0;  
    int count = 0;  

    while (i < n) {
        if (pattern[j] == str[i]) {
            i++;
            j++;
        }

        if (j == m) {  
            count++;  
            j = lps[j - 1];  
        }
        else if (i < n && pattern[j] != str[i]) {  
            if (j != 0) {
                j = lps[j - 1];  
            }
            else {
                i++;  
            }
        }
    }

    return count;
}