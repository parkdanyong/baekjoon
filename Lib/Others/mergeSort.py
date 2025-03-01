'''
    merge sort
    average: O(nlogn)   
'''

# merge sort
def merge(arr1, arr2) :
    size1 = len(arr1)
    size2 = len(arr2)
    i1 = 0
    i2 = 0
    result = []

    while (i1 < size1 and i2 < size2) :
        if (arr1[i1] < arr2[i2]) :
            result.append(arr1[i1])
            i1 += 1
        else :
            result.append(arr2[i2])
            i2 += 1
    
    result.extend(arr1[i1:])
    result.extend(arr2[i2:])

    return result


def mergeSort(arr) :
    size = len(arr)
    if (size < 2) :
        return arr
    
    mid = size // 2
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])

    return merge(left, right)