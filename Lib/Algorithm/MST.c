/*
    MST (Minimum Spanning Tree)
    
    Spanning Tree (신장 트리)
        connected graph 내의 모든 정점을 포함하지만 사이클이 없는 트리로, 그래프의 최소 연결 부분 그래프다.
        여기서 "최소 연결"은 간선의 수가 가장 적은 것을 의미한다.
        n개의 정점을 가지는 그래프의 최소 간선의 수는 (n-1)개이다.
    
    MST
        스패닝 트리가 여러개 존재할 수 있기 때문에, 간선의 가중치가 가장 작은 트리를 찾는다.


    Algorithms
    1. Kruskal's Algorithm
        간선을 가중치 순서대로 정렬한 후, 가장 작은 가중치의 간선을 선택하며 사이클이 생기지 않도록 연결하는 방식
        대표적으로 유니온-파인드(Union-Find) 자료구조를 사용하여 사이클 여부를 판별


    2. Prim's Algorithm
        하나의 정점에서 시작하여 가장 가중치가 작은 간선을 추가하는 방식
        우선순위 큐(Heap)을 사용하여 구현하면 효율적
    
        
    응용 분야
    1. 네트워크 설계
    2. 회로 설계
    3. 도로망 설계

*/



typedef struct Edge{
    int u; 
    int v; 
    int w; 
}edge;


int V, E;
edge* arr;
int* parent;
int* rank;


int compare(const void* arg1, const void* arg2) {
    edge* a = (edge*) arg1;
    edge* b = (edge*) arg2;
    return a->w - b->w;
}


void initSet() {
    for (int i = 0; i <= V; i++) {
        parent[i] = i;
        rank[i] = 1;
    }
}


int Find(int ver) {
    if (parent[ver] == ver) return ver;
    return parent[ver] = Find(parent[ver]); // Path Compression
}


int Union(int v1, int v2) {
    int v1_p = Find(v1);
    int v2_p = Find(v2);

    if (v1_p != v2_p) {
        if (rank[v1_p] > rank[v2_p]) parent[v2_p] = v1_p;
        else if (rank[v1_p] < rank[v2_p]) parent[v1_p] = v2_p;
        else {
            parent[v2_p] = v1_p;
            rank[v1_p] += 1;
        }
        return 1;
    }
    return 0;
}


int kruskal() {
    qsort(arr, E, sizeof(edge), compare);

    
    int acceptedEdge = 0;
    int weightSum = 0;
    edge cur;
    for (int i = 0; i < E; i++) {
        if (acceptedEdge >= V - 1) break;
        cur = arr[i];
        if (Union(cur.u, cur.v)) {
            weightSum += cur.w;
            acceptedEdge += 1;
        }
    }
    return weightSum;
}