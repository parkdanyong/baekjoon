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


class Queue:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0


    def push(self, data):
        newNode = Node(data)
        if self.__size != 0 :
            self.__tail.setNext(newNode)
        else:
            self.__head = newNode

        self.__tail = newNode
        self.__size += 1


    def pop(self):
        if self.__size == 0:
            return -1

        temp = self.__head
        if self.__size == 1:
            self.__head = None
            self.__tail = None
        else :
            self.__head = self.__head.getNext()
            temp.setNext(None)
        
        self.__size -= 1

        return temp.getData()


    def size(self):
        return self.__size


    def empty(self):
        if self.__size == 0 :
            return 1
        else :
            return 0


    def front(self):
        if self.__size == 0:
            return -1

        return self.__head.getData()


    def back(self):
        if self.__size == 0:
            return -1

        return self.__tail.getData()


def select(queue, ins):
    if (ins[0] == "push"):
        queue.push(ins[1])
    elif (ins[0] == "pop"):
        print(queue.pop())
    elif (ins[0] == "size"):
        print(queue.size())
    elif (ins[0] == "empty"):
        print(queue.empty())
    elif (ins[0] == "front"):
        print(queue.front())
    elif (ins[0] == "back"):
        print(queue.back())


queue = Queue()
count = int(sys.stdin.readline())
for i in range(count):
    instruction = sys.stdin.readline().split()
    select(queue, instruction)
