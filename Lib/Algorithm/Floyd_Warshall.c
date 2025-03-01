/*
    O(n^3)
*/


int min(int a, int b) {
    return a < b ? a : b;
}


void floydWarshall(int* matrix, int n, int* dis) {
    int size = n * n;
    for (int i = 0; i < size; i++) { // copy
        dis[i] = matrix[i];
    }


    for (int k = 1; k <= n; k++) { // path visiting node k
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {
                dis[i*(n+1) + j] =  min(dis[i*(n+1) + j], dis[i*(n+1) + k] + dis[k*(n+1) + j]);
            }
        }
    }
}