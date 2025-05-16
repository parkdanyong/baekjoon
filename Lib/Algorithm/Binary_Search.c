int upperBound(int n, int* arr, int len) {
    int low = -1;
    int high = len;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (arr[mid] <= n) low = mid;
        else high = mid;
    }
    return high;
}


int lowerBound(int n, int* arr, int len) {
    int low = -1;
    int high = len;
    int mid;
    while (low+1 < high) {
        mid = low + (high - low) / 2;
        if (n <= arr[mid]) high = mid;
        else low = mid;
    }
    return low;
}


int binarySearch(int n, int* arr, int len) {
    int low = 0;
    int high = len-1;
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (n < arr[mid]) high = mid-1;
        else if (arr[mid] < n) low = mid+1;
        else return mid;
    }
    return -1;
}