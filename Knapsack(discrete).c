#include <stdio.h>
#include <stdlib.h>

int knapSackRec(int W, int wt[], int val[], int index, int** dp) {
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];

    if (wt[index] > W) {
        dp[index][W] = knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    } else {
        dp[index][W] = (val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp) > knapSackRec(W, wt, val, index - 1, dp)) 
                       ? (val[index] + knapSackRec(W - wt[index], wt, val, index - 1, dp)) 
                       : knapSackRec(W, wt, val, index - 1, dp);
        return dp[index][W];
    }
}

int knapSack(int W, int wt[], int val[], int n) {
    int** dp = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        dp[i] = (int*)malloc((W + 1) * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j] = -1;

    int result = knapSackRec(W, wt, val, n - 1, dp);

    for (int i = 0; i < n; i++)
        free(dp[i]);
    free(dp);

    return result;
}

int main() {
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("%d\n", knapSack(W, weight, profit, n));
    return 0;
}
