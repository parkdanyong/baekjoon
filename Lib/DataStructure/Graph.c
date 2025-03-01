/*
    Graph
    연결되어 있는 객체 간의 관계를 표현하는 자료구조


    용어
    Weighted graph (가중치 그래프): 간선에 가중치가 할당된 그래프
    Subgraph (부분 그래프)
    Adjacent vertex (인접 정점): 간선에 의해 직접 연결된 정점
    Degree (차수): 특정 정점에 연결된 간선의 수
        - 무방향 그래프의 차수 합은 간선 수의 2배
        - 방향 그래프
            in-degree (진입차수): 특정 정점으로 들어오는 간선의 수
            out-degree (진출차수): 특정 정점에서 나가는 간선의 수
            in/out degree의 합은 간선의 수
    Path (경로): 정점 u로부터 정점 v까지의 경로 (정점, 간선 둘다 가능)
    Lenght (경로의 길이): 경로에 사용된 간선의 수
    Simple path (단순 경로): 경로 중에서 반복되는 간선(정점)이 없는 경로
    Cycle (사이클): 시작 정점과 종료 정점이 동일한 경로
    Spanning tree (신장 트리): 그래프 내의 모든 정점을 포함하는 트리


    Undirected graph (무방향 그래프)
        - Connected graph (연결 그래프): 모든 정점들 사이에 path가 존재하는 그래프
        - Not connected graph: maximal connected subgraph(connected component: 무방향 그래프에서 모든 정점이 서로 연결된 하나의 독립적인 부분 그래프)의 집합으로 이루어지는 그래프
        - Tree (트리): 사이클을 가지지 않는 연결 그래프
        - Complete graph (완전 그래프): 모든 정점간에 간선이 존재하는 그래프, n개의 정점을 가진 무방향 완전 그래프 간선의 수 = n*(n-1)/2


    Directed graph (방향 그래프)
        - Reachability in directed graph: 정점 u에서 정점 v 사이에 path가 존재하면, rechable (접근 가능)
        - Strongly connected: 임의의 u와 v가 서로 접근 가능하면 정점 v와 u는 강한 연결되었다고 한다.
        - Strongly connected graph: 만일 모든 정점이 나머지 정점에 이르는 경로를 가지면 
        - DAG (directed acyclic graph): 사이클이 없는 directed graph


    
*/