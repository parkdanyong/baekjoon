import sys


class Node:
    def __init__(self, data):
        self.__data = data
        self.__next = None

    def getData(self):
        return self.__data

    def getNext(self):
        return self.__next

    def setData(self, data):
        self.__data = data

    def setNext(self, next):
        self.__next = next


class Stack:
    def __init__(self):
        self.__top = None
        self.__size = 0

    def push(self, data):
        newNode = Node(data)

        if self.__top != None:
            newNode.setNext(self.__top)

        self.__top = newNode
        self.__size += 1

    def pop(self):
        if self.__size == 0:
            return -1

        temp = self.__top
        self.__top = self.__top.getNext()
        temp.setNext(None)

        self.__size -= 1

        return temp.getData()
            

    def size(self):
        return self.__size

    def empty(self):
        if self.__size == 0:
            return 1
        else:
            return 0

    def top(self):
        if self.__size != 0:
            return self.__top.getData()
        else:
            return -1


def select(data, stack):
    if (data[0] == "push"):
        stack.push(data[1])
    elif (data[0] == "pop"):
        print(stack.pop())
    elif (data[0] == "empty"):
        print(stack.empty())
    elif (data[0] == "size"):
        print(stack.size())
    elif (data[0] == "top"):
        print(stack.top())


stack = Stack()
count = int(sys.stdin.readline())
for i in range(count):
    instruction = sys.stdin.readline()
    select(instruction.split(), stack)
