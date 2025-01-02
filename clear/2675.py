import sys


count = int(sys.stdin.readline())
for i in range(count) :
    tmp = sys.stdin.readline().split()
    repeat = int(tmp[0])
    for c in tmp[1] :
        print(f"{c * repeat}", end="")
    print()