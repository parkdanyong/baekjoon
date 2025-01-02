import sys

myDict = dict()


siteCount, searching = sys.stdin.readline().split()
for i in range(int(siteCount)) :
    site, password = sys.stdin.readline().split()
    myDict[site] = password


for i in range(int(searching)) :
    site = sys.stdin.readline().strip()
    print(myDict[site])
