/*
    
*/

int removeDuplicates(int* arr, int n) {
    int len = 0;

    for (int i = 1; i < n; i++) {
        if (arr[len] != arr[i]) {
            len++;
            arr[len] = arr[i];
        }
    }

    return len + 1;
}