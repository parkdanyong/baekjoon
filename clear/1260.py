'''
    title: DFS와 BFS
    tag: graph, BFS, DFS

    graph using list
'''


import sys



class Graph :
    def __init__(self) :
        self.graph = []
    

    def DFS(self, start=0, visited=list()) :
        stack = [start]
        cur = 0
        
        while (len(stack) != 0) :
            cur = stack.pop()
            if (cur not in visited) :
                print(cur+1, end=" ")
                visited.append(cur)
                for node in sorted(self.graph[cur], reverse=True) :
                    stack.append(node)
        
        print()
    

    def BFS(self, start=0, visited=list()) :
        queue = [start]
        cur = 0

        while (len(queue) != 0) :
            cur = queue.pop(0)
            if (cur not in visited) :
                print(cur+1, end=" ")
                visited.append(cur)
                for node in sorted(self.graph[cur]) :
                    queue.append(node)
        
        print()




# code test
# init
g = Graph()
vartex = 0
edge = 0
start = 0


# using input file 
# with open("inputFile.txt", "r") as file :
#     vartex, edge, start = [int(i) for i in file.readline().split()]
#     start -= 1

#     for i in range(vartex) :
#         g.graph.append([])

#     for i in range(edge) :
#         tmp = [int(i)-1 for i in file.readline().split()]
#         g.graph[tmp[0]].append(tmp[1])
#         g.graph[tmp[1]].append(tmp[0])


# using stdin for submit
vartex, edge, start = [int(i) for i in sys.stdin.readline().split()]
start -= 1
for i in range(vartex) :
    g.graph.append([])
for i in range(edge) :
    tmp = [int(i)-1 for i in sys.stdin.readline().split()]
    g.graph[tmp[0]].append(tmp[1])
    g.graph[tmp[1]].append(tmp[0])


# run
g.DFS(start=start)
g.BFS(start=start)