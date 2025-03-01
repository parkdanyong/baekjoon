'''
    standard: ascending order, not descending order
'''




def upperBound(arr, n) :
    ''' 
        :parameter arr: source array
        :parameter target: target to find range 
        :return: first index of larger then target
    '''


    low = -1
    high = len(arr)
    while (low + 1 < high) :
        mid = low + (high - low) // 2

        if (arr[mid] <= n) :
            low = mid
        else :
            high = mid

    return high


def lowerBound(arr, n) :
    ''' 
        :parameter arr: source array
        :parameter target: target to find range 
        :return: last index of smaller then target
    '''


    low = -1
    high = len(arr)
    while (low + 1 < high) :
        mid = low + (high - low) // 2

        if (arr[mid] >= n) :
            high = mid
        else :
            low = mid

    return low