class queuestack :
    def __init__(self, N) :
        self.size = N
        self.arr = list(range(N))
    

    def build(self) :
        ds = [int(n) for n in input().split()]
        val = [int(n) for n in input().split()]


        for i in range(self.size) :
            self.arr[i] = [ds[i], [val[i]]]
        

    def insert(self, val) :
        for i in range(self.size) :
            if (self.arr[i][0] == 0) : # queue
                self.arr[i][1].append(val)
                val = self.arr[i][1].pop(0)
            else : # stack
                self.arr[i][1].append(val)
                val = self.arr[i][1].pop()
        
        return val



def main() :
    N = int(input())
    qs = queuestack(N)
    qs.build()
    
    T = int(input())
    inputList = [int(n) for n in input().split()]
    for i in range(T) :
        print(qs.insert(inputList[i]), end=" ")


main()