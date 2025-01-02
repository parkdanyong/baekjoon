import sys


mylib = dict()


def fib(n):
    if n <= 2:
        return 1

    if n in mylib :
        return mylib[n]
    else :
        tmp = fib(n - 1) + fib(n - 2)
        mylib[n] = tmp
        return tmp


n = int(sys.stdin.readline().strip())
print(fib(n))