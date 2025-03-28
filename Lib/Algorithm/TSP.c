/*
    Traveling Salesman problem 

    모든 정점을 한 번씩 순회하며 시작 지점으로 순환하는 최솟값
*/


#define min(X, Y) (X) < (Y) ? (X) : (Y)
#define BITMASK 1024
#define CITY 10
#define INF 10000000


int N, size;
int* graph;
int dp[BITMASK][CITY];



int tsp(int visited, int cur) {
    if (visited == (1 << N) - 1) return graph[N*cur] ? graph[N*cur] : INF;
    else if (dp[visited][cur] != -1) return dp[visited][cur];


    int minCost = INF;
    for (int next = 0; next < N; next++) {
        if ((visited & (1 << next)) == 0 && graph[N*cur + next] != 0) {
            minCost = min(minCost, graph[N*cur + next] + tsp(visited | (1 << next), next));
        }
    }

    return dp[visited][cur] = minCost;
}