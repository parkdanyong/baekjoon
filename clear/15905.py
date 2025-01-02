'''
    title: 스텔라(STELLA)가 치킨을 선물했어요
    tag: sorting


    The list sorted descending order.
    Upper, lower bound function have changed slightly.
'''




import sys




def upperBound(arr, target) :
    low = -1
    high = len(arr)

    while (low + 1 < high) :
        mid = low + (high - low) // 2
        
        if (arr[mid][0] <= target) :
            high = mid
        else :
            low = mid
    
    return low 

        

def lowerBound(arr, target) :
    low = -1
    high = len(arr) 

    while (low + 1 < high) :
        mid = low + (high - low) // 2

        if (arr[mid][0] >= target) :
            low = mid 
        else :
            high = mid 
    
    return high




# input data
c = int(sys.stdin.readline())
students = []
for i in range(c) :
    tmp = sys.stdin.readline().split()
    students.append([int(element) for element in tmp])


# students = []
# with open("inputFile.txt", "r") as file :
#     c = int(file.readline())
#     for i in range(c) :
#         tmp = file.readline().split()
#         students.append([int(element) for element in tmp])



students.sort(key= lambda x: (x[0]), reverse=True)
score = 0
count = 1
for i in range(5) :
    if (score == students[i][0]) :
        count += 1 
    else :
        score = students[i][0]
        count = 1



result = lowerBound(students, score) - upperBound(students, score) - 1 - count
print(result)


    
