/*
    Union Find
*/


int N;
int* parent;
int* rank;


void initList() {
    for (int i = 0; i < N; i++) {
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