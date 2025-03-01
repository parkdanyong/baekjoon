'''
    quick sort
    average: O(nlogn)
    worst: O(n^2)
'''


# quick sort
def swap(arr, low, high) :
    tmp = arr[low]
    arr[low] = arr[high]
    arr[high] = tmp


def partition(arr, left, right) :
    low = left
    high = left
    pivotIndex = right
    pivot = arr[pivotIndex]
    

    while (low < pivotIndex) :
        if (arr[low] < pivot) :
            swap(arr, low, high)
            high += 1

        low += 1

    swap(arr, high, pivotIndex) 
    return high


def quickSort(arr, left, right) :
    if (not left < right) :
        return 
    
    p = partition(arr, left, right)
    quickSort(arr, left, p - 1)
    quickSort(arr, p + 1, right)