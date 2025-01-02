import sys



def pooling(matrix):
    size = len(matrix)
    if size == 2:
        v = list(matrix[0])
        v.extend(matrix[1])
        v.sort(reverse=True)
        return v[1]



    filter = []
    for i in range(size//2):
        colVector = []

        for j in range(size//2):
            subMatrix = [row[j*2:j*2 + 2] for row in matrix[i*2:i*2 + 2]] # 2x2 size filter
            result = pooling(subMatrix)
            colVector.append(result) 

        filter.append(colVector)

    return pooling(filter)




size = int(sys.stdin.readline())
matrix = []
for i in range(size):
    tmp = sys.stdin.readline().split()
    matrix.append([int(element) for element in tmp])


print(pooling(matrix))

