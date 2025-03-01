'''
    title: 숫자 카드 
    tag: merge sort, binary search, lower_bound, upper_bound
    

    merge sort: O(nlogn)
    binary search -> lower_bound + upper_bound: O(logn)
    total: O(nlogn)


    reference: https://www.acmicpc.net/blog/view/109
'''



import sys





def merge(arr1, arr2) :
    result = []
    i1 = 0
    i2 = 0

    # loop until one of them is empty
    while (i1 < len(arr1) and i2 < len(arr2)) : 
        # push min(arr1[0], arr2[0])
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
    else :
        # 1.divide: split into 2 list
        mid = len(arr) // 2

        arr1 = mergeSort(arr[:mid])
        arr2 = mergeSort(arr[mid:])

        # 2.conquer: sort 
        # 3.combine: merge 2 list
        return merge(arr1, arr2)



def binarySearch(arr, target) :
    '''
        parameter arr: a list has duplicate element
        parameter target: data to find range
        return: the size of target's range, upper bound - lower bound

        call lower bound and upper bound
    '''
    return upperBound(arr, target) - lowerBound(arr, target)


def upperBound(arr, target) :
    '''
        parameter arr: a list has duplicate element
        parameter target: data to find range for upper bound
        return: a value satisfies target < arr[high]
        
    '''
    low = -1
    high = len(arr)

    while (low + 1 < high) :
        mid = low + (high - low) // 2
        
        if (arr[mid] <= target) :
            low = mid 
        else : # arr[high:] do not contain the target, this means high can be the upper bound 
            high = mid 
    
    return high # high is the minimum bound for target < arr[high] 
    

def lowerBound(arr, target) :
    '''
        parameter arr: a list has duplicate element
        parameter target: data to find range for lower bound
        return: a value satisfies arr[high] <= target
    '''
    low = -1
    high = len(arr)

    while (low + 1 < high) :
        mid = low + (high - low) // 2
        
        if (target <= arr[mid]) :
            high = mid 
        else : # arr[:low] do not contain the target, this means high can be the lower bound
            low = mid 
    
    return high # low is the minimum bound for arr[high] <= target




# code test
# init arr
size = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
arr = []
for i in tmp:
    arr.append(int(i))


# init targetArr
size = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
targetArr = []
for i in tmp :
    targetArr.append(int(i))


# sort
sorted = mergeSort(arr) 


for t in targetArr :
    print(binarySearch(sorted, t), end=" ")
