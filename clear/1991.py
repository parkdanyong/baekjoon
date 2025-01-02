'''
    title: 트리 순회
    tag: tree, (preoder, inoder, postoder) traversal 
'''


import sys


class Node :
    def __init__(self, data):
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




class Tree :
    def __init__(self):
        self.__root = None
    

    def isEmpty(self) :
        return self.__root == None


    def search(self, data) :
        queue = [self.__root]

        while (len(queue) != 0) :
            cur = queue.pop(0)
            
            if (cur.getData() == data) :
                return cur 

            if (cur.getLeft() != None) :
                queue.append(cur.getLeft())
            if (cur.getRight() != None) :
                queue.append(cur.getRight())

        return None


    def insertRoot(self, root) :
        self.__root = root
    

    def preoder(self) :
        stack = [self.__root]

        while (len(stack) != 0) :
            cur = stack.pop()

            print(cur.getData(), end="")
            if (cur.getRight() != None) :
                stack.append(cur.getRight())
            if (cur.getLeft() != None) :
                stack.append(cur.getLeft())
        print()


    def inoder(self) :
        stack = []
        cur = self.__root

        while (len(stack) != 0 or cur != None) :
            # move left 
            while (cur != None) : 
                stack.append(cur)
                cur = cur.getLeft()

            # active cur
            cur = stack.pop() 
            print(cur.getData(), end="")

            # move right 
            cur = cur.getRight() 
        print()


    def postoder(self) :
        stack = []
        lastVisit = None
        cur = self.__root

        while (len(stack) != 0 or cur != None) :
            # move left
            while (cur != None) :
                stack.append(cur)
                cur = cur.getLeft()
            
            top = stack[-1]

            # move right
            if (top.getRight() != None and top.getRight() != lastVisit) :
                cur = top.getRight()
            else :
                # active cur
                print(top.getData(), end="")
                lastVisit = stack.pop()
        print()



# code test
tree = Tree()
size = int(sys.stdin.readline())
for i in range(size) :
    cur, left, right = sys.stdin.readline().split()

    if (tree.isEmpty()) :
        cur = Node(cur)
        tree.insertRoot(cur)
    else :
        cur = tree.search(cur)

    if (left != ".") :
        cur.setLeft(Node(left))
    if (right != ".") :
        cur.setRight(Node(right))


tree.preoder()
tree.inoder()
tree.postoder()

