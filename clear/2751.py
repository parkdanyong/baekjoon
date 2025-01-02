'''
    title: 수 정렬하기2
    tag: quick sort, merge sort


    merge sort
    average: O(nlogn)
'''


import sys


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




# code test
# size = 0
# arr = []
# with open("inputFile.txt", "r", encoding="utf-8") as file :
#     size = int(file.readline())
#     for line in file:
#         arr.append(int(line.strip()))


size = int(sys.stdin.readline())
arr = []
for i in range(size) :
    arr.append(int(sys.stdin.readline()))


sorted = mergeSort(arr)
for i in sorted :
    print(i)