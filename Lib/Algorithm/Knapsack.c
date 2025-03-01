/*
    0-1 Knapsack Problem (0-1 배낭 문제)
        O(nw)
        dp[i][w] = max(dp[i−1][w],dp[i−1][w−wi] + vi)
        공간 복잡도를 O(w)으로 줄이는 최적화 알고리즘도 있음
​
 
    Fractional Knapsack Problem (분할 가능 배낭 문제)
        O(nlogn)


    응용 분야
        1. 자원 배분 문제 (예: 예산 내에서 최대한 효과적인 투자)
        2. 데이터 압축 (최적의 데이터 저장 방법 선택)
        3. 배터리 최적화 (제한된 전력으로 최대한 긴 시간 작동)
        4. 물류 최적화 (최소한의 비용으로 가장 가치 있는 물품 배송)


*/

typedef struct Stuff {
    int W;
    int V;
}stuff;


int knapsack(stuff* arr, int n, int w) {
    int* bag = (int*) calloc((n+1)*(w+1), sizeof(int));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= w; w++) {
            if (w < arr[i].W) bag[(w+1)*i + w] = bag[(w+1)*(i-1) + w];
            else bag[(w+1)*i + w] = max(bag[(w+1)*(i-1) + w], bag[(w+1)*(i-1) + (w - arr[i].W)] + arr[i].V);
        }
    }

    int result = bag[(w+1)*n + w];
    free(bag);
    return result;
}