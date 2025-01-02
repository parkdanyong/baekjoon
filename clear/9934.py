'''
    title: 완전 이진 트리
    tag: #자료구조

    complete binary tree using linked node, not array
    assume no duplicate
    inoder traversal: LVR
    level traversal -> BFS (using queue)
'''

import sys






class Node :
    def __init__(self, data) :
        self.__data = data
        self.__left = None
        self.__right = None
    
    
    def getData(self) :
        return self.__data

    def getLeft(self) :
        return self.__left
    
    def getRight(self) :
        return self.__right

    def setData(self, data) :
        self.__data = data
    
    def setLeft(self, left) :
        self.__left = left
    
    def setRight(self, right) :
        self.__right = right




class CBT : # complete binary tree 
    def __init__(self) :
        self.__root = None 
    

    def create(self, data) :
        return Node(data)


    def insert(self, data) : 
        newNode = self.create(data)
        if self.__root == None : # empty
            self.__root = newNode
            return


        queue = [self.__root]
        while (len(queue) != 0) :
            cur = queue.pop(0)
            if cur.getLeft() == None : 
                cur.setLeft(newNode) # insert left
                break
            elif cur.getRight() == None :
                cur.setRight(newNode) # insert right
                break
            queue.append(cur.getLeft())
            queue.append(cur.getRight())



    def inoder(self, visitList) :
        stack = [self.__root]

        cur = self.__root
        while len(visitList) != 0 :
            if cur != None :
                stack.append(cur)
                cur = cur.getLeft()
            else :
                cur = stack.pop()
                cur.setData(visitList.pop(0))
                cur = cur.getRight()

    
    def drawTree(self) :
        queue = [[self.__root, 0]]
        depth = 0
        
        while len(queue) != 0 :
            cur, tmp = queue.pop(0)
            
            if tmp != depth :
                depth += 1
                print()
            print(cur.getData(), end=" ")

            if cur.getLeft() != None :
                queue.append([cur.getLeft(), tmp+1])
            if cur.getRight() != None :
                queue.append([cur.getRight(), tmp+1])
            

            

# code test
level = int(sys.stdin.readline())
nodeCount = 2 ** level - 1

visitList = sys.stdin.readline().split()
visitList = [int(element) for element in visitList]

# create tree
myCBT = CBT()
for i in range(nodeCount) :
    myCBT.insert(0)


# init tree
myCBT.inoder(visitList)

myCBT.drawTree()
