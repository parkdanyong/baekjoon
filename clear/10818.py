'''
    title: 최소, 최대
    tag: merge sort
'''



import sys


def merge(arr1, arr2) :
    result = []
    i1 = 0
    i2 = 0

    while (i1 < len(arr1) and i2 < len(arr2)) :
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
    if (len(arr) < 2) :
        return arr
    
    mid = len(arr) // 2
    
    arr1 = mergeSort(arr[:mid])
    arr2 = mergeSort(arr[mid:])

    return merge(arr1, arr2)




# code test
size = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
arr = [int(element) for element in tmp]

sorted = mergeSort(arr)
print(f"{sorted[0]} {sorted[-1]}")