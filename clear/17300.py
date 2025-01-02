'''
    title: 패턴
    tag: array


    1 2 3
    4 5 6
    7 8 9


    짝수는 간에 합이 10인 패턴은 5번 확인 필요
    홀수 모서리는 각 모서리 간에 (본인과 다음 숫자의 합 // 2) 확인 필요 
'''



import sys




# input
check = [0] * 9
length = int(sys.stdin.readline())
tmp = sys.stdin.readline().split()
pattern = [int(element) for element in tmp]


# with open("inputFile.txt", "r") as file :
#     length = int(file.readline())
#     tmp = file.readline().split()
#     pattern = [int(element) for element in tmp]



flag = True
check[pattern[0]-1] = 1
for i in range(1, length) :
    if (check[pattern[i] - 1] == 1) : # 패턴 중복
        print("NO")
        flag = False
        break
    elif (pattern[i] % 2 == 0) : # even
        if (pattern[i] + pattern[i-1] == 10 and check[4] == 0) : # (2, 8), (4, 6) 일 때, 5가 0이면 NO
            print("NO")
            flag = False
            break 
    else : # odd
        if not (pattern[i] == 5 or pattern[i-1] == 5) : # 5는 패스
            tmp = (pattern[i] + pattern[i-1])
            
            if (tmp % 2 == 0 and check[tmp//2 - 1] == 0) : # 모서리 사이값이 0이면 NO
                print("NO")
                flag = False
                break

    check[pattern[i] - 1] = 1


if (flag) :
    print("YES")

