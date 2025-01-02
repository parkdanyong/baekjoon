'''
    tytle: 또 수열 문제야
    tag: 

    합이 짝수, 곱이 홀수면 당연히 약수가 될 수 없다.
    2n - 1

'''



import sys


n = int(sys.stdin.readline())
for i in range(1, 2 * n, 2) :
    print(i, end=" ")
