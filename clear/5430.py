'''
    title: AC
    tag: dequeue, string, parsing

    I solved it using modified circular queue.
    
'''




import sys



class CircularQueue() :
    def __init__(self, size) :
        self.arr = list(range(size))
        self.size = size
        self.front = 0
        self.rear = 0
        self.clockwise = True


    def clear(self) :
        self.front = 0
        self.rear = 0
        self.clockwise = True
    

    def reverse(self) :
        if (self.clockwise) :
            self.clockwise = False
            tmp = self.rear
            self.rear = (self.front + 1) % self.size 
            self.front = (tmp + 1) % self.size
        else :
            self.clockwise = True
            tmp = self.rear
            self.rear = (self.size + self.front - 1) % self.size 
            self.front = (self.size + tmp - 1) % self.size


    def enqueue(self, data) :
        tmp = 0
        if (self.clockwise) :
            tmp = (self.rear + 1) % self.size 
        else :
            tmp = (self.size + self.rear - 1) % self.size 
        if (self.front == tmp) :
            return

        self.rear = tmp
        self.arr[self.rear] = data
    

    def dequeue(self) :
        if (self.front == self.rear) :
            return -1
        
        if (self.clockwise) :
            self.front = (self.front + 1) % self.size 
        else :
            self.front = (self.size + self.front - 1) % self.size 

        return self.arr[self.front]


def answer(cq, command) :
    length = len(command)
    for i in range(length) :
        if (command[i] == "D") :
            if (cq.dequeue() == -1) :
                print("error")
                return 
        else :
            cq.reverse()


    n = cq.dequeue() 
    print("[", end="")
    while (n != -1) :
        print(n, end="")
        n = cq.dequeue()
        if (n == -1) :
            break
        print(",", end="")
    print("]")





# with open("inputFile.txt", "r") as file :
#     t = int(file.readline())
#     cq = CircularQueue(100001)
#     for i in range(t) :
#         command = file.readline().strip()
#         size = int(file.readline())
#         tmpArr = file.readline()
#         tmpArr = tmpArr[1:len(tmpArr)-2].split(",")
#         if (tmpArr[0] != "") :
#             for n in tmpArr :
#                 cq.enqueue(int(n))
#         answer(cq, command)
#         cq.clear()



# input
t = int(sys.stdin.readline())
cq = CircularQueue(100001)
for i in range(t) :
    command = sys.stdin.readline().strip()
    size = int(sys.stdin.readline())
    tmpArr = sys.stdin.readline()
    tmpArr = tmpArr[1:len(tmpArr)-2].split(",")
    if (tmpArr[0] != "") :
        for n in tmpArr :
            cq.enqueue(int(n))
    answer(cq, command)
    cq.clear()

