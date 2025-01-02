import sys



def paperDivide(paper) :
    global whiteCount
    global blueCount


    size = len(paper)
    color = paper[0][0]
    flag = False


    if size == 1 :
        if color == 0 :
            whiteCount += 1
            return
        else :
            blueCount += 1
            return


    # check the paper's color
    for i in range(size) :
        for j in range(size) :
            if paper[i][j] != color :
                flag = True
                break


    if flag :
        half = size//2
        left_top = [row[:half] for row in paper[:half]]
        right_top = [row[half:] for row in paper[:half]]
        left_bottom = [row[:half] for row in paper[half:]]
        right_bottom = [row[half:] for row in paper[half:]]

        paperDivide(left_top)
        paperDivide(right_top)
        paperDivide(left_bottom)
        paperDivide(right_bottom)
    else :
        if color == 0 :
            whiteCount += 1
        else :
            blueCount += 1



# init data
size = int(sys.stdin.readline())
whiteCount = 0
blueCount = 0
paper = []
for i in range(size) :
    tmp = [int(element) for element in sys.stdin.readline().split()]
    paper.append(tmp)




paperDivide(paper)
print(whiteCount)
print(blueCount)



