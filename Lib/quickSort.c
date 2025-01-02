int partition(int* arr, int size, int start, int end) {
    int b = start; // big group index
    int s = start; // small group index
    int p = (int) (start + (end - start) / 2); // pivot
    int pivotElement = arr[p];

    while (s != end) {
        if (s == p) {
            s++;
        }
        if (arr[s] < pivotElement) {
            int tmp = arr[b];
            arr[b] = arr[s];
            arr[s] = tmp;
            b++;
        }
        s++;
    }

    int tmp = arr[b];
    arr[b] = arr[p];
    arr[p] = tmp;

    return b; // after swapping, arr[b] is pivot element
}




void quickSort(int* arr, int size, int start, int end) {
    if (start >= end) return;
    // divide 
    int pivot = partition(arr, size, start, end);
    
    // left sort
    if (pivot != start) quickSort(arr, size, start, pivot-1);
    // right sort
    if (pivot != end) quickSort(arr, size, pivot+1, end);
}