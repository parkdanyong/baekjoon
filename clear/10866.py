import sys


class Node:
    def __init__(self, data):
        self.__data = data
        self.__pre = None
        self.__next = None

    def getData(self):
        return self.__data

    def getPre(self):
        return self.__pre

    def getNext(self):
        return self.__next

    def setData(self, data):
        self.__data = data

    def setPre(self, pre):
        self.__pre = pre

    def setNext(self, next):
        self.__next = next


class Deque:
    def __init__(self):
        self.__head = None
        self.__tail = None
        self.__size = 0

    def push_front(self, data):
        newNode = Node(data)

        if self.__size != 0:
            self.__head.setPre(newNode)
            newNode.setNext(self.__head)
        else:
            self.__tail = newNode
        self.__head = newNode

        self.__size += 1

    def push_back(self, data):
        newNode = Node(data)

        if self.__size != 0:
            self.__tail.setNext(newNode)
            newNode.setPre(self.__tail)
        else:
            self.__head = newNode
        self.__tail = newNode

        self.__size += 1

    def pop_front(self):
        if self.__size == 0:
            return -1

        temp = self.__head
        if self.__size == 1:
            self.__head = None
            self.__tail = None
        else:
            self.__head = self.__head.getNext()
            self.__head.setPre(None)
            temp.setNext(None)

        self.__size -= 1

        return temp.getData()

    def pop_back(self):
        if self.__size == 0:
            return -1

        temp = self.__tail
        if self.__size == 1:
            self.__head = None
            self.__tail = None
        else:
            self.__tail = self.__tail.getPre()
            self.__tail.setNext(None)
            temp.setPre(None)

        self.__size -= 1

        return temp.getData()

    def size(self):
        return self.__size

    def empty(self):
        if self.__size == 0:
            return 1
        else:
            return 0

    def front(self):
        if self.__size == 0:
            return -1

        return self.__head.getData()

    def back(self):
        if self.__size == 0:
            return -1

        return self.__tail.getData()


def select(deque, ins):
    if ins[0] == "push_front":
        deque.push_front(ins[1])
    elif ins[0] == "push_back":
        deque.push_back(ins[1])
    elif ins[0] == "pop_front":
        print(deque.pop_front())
    elif ins[0] == "pop_back":
        print(deque.pop_back())
    elif ins[0] == "size":
        print(deque.size())
    elif ins[0] == "empty":
        print(deque.empty())
    elif ins[0] == "front":
        print(deque.front())
    elif ins[0] == "back":
        print(deque.back())


deque = Deque()
count = int(sys.stdin.readline())
for i in range(count):
    instruction = sys.stdin.readline().split()
    select(deque, instruction)
