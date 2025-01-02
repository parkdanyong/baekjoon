'''
    title: 네트워크 연결
    tag: graph, 
'''



import sys 



def find(n) :
    if (parent[n] == n) :
        return n 
    parent[n] = find(parent[n])
    return parent[n]


def union(a, b) :
    pa = find(a)
    pb = find(b)

    if (pa == pb) :
        return False

    parent[pa] = pb
    
    return True 




def merge(arr1, arr2) :
    result = []
    i1 = 0
    i2 = 0

    # loop until one of them is empty
    while (i1 < len(arr1) and i2 < len(arr2)) : 
        # push min(arr1[0], arr2[0])
        if (arr1[i1][2] < arr2[i2][2]) :
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





def solve(n) :
    global result
    global sortedGraph

    i = 0
    e = 0
    while (True) :
        if (union(sortedGraph[i], sortedGraph[i])) :
            result += sortedGraph[i][2] 
            e += 1
        if (n-1 == e) :
            break 





# code test
# n = int(sys.stdin.readline())
# m = int(sys.stdin.readline())

parent = []
# for i in range(m) :
#     tmp = sys.stdin.readline().split()
#     parent.append([int(element) for element in tmp])


result = 0


n = 0
m = 0
with open("inputFile.txt", "r") as file :
    n = int(file.readline())
    m = int(file.readline())
    
    for i in range(m) :
        tmp = file.readline().split()
        parent.append([int(element) for element in tmp])


# sort 
sortedGraph = mergeSort(parent)
solve(n)
print(result)

