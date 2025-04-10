#include <stdio.h>
#include <limits.h>
#include <time.h>
#define MAX 100

int dp[MAX][MAX];
int split[MAX][MAX];

void printOptimalParenthesis(int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParenthesis(i, split[i][j]);
        printOptimalParenthesis(split[i][j] + 1, j);
        printf(")");
    }
}

int matrixChainMemoized(int p[], int i, int j) {
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int minCost = INT_MAX;
    int k, cost;

    for (k = i; k < j; k++) {
        cost = matrixChainMemoized(p, i, k) +
               matrixChainMemoized(p, k + 1, j) +
               p[i - 1] * p[k] * p[j];

        if (cost < minCost) {
            minCost = cost;
            split[i][j] = k;
        }
    }

    dp[i][j] = minCost;
    return minCost;
}

int main() {
    int n;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];
    printf("Enter the dimensions array of size %d: ", n + 1);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    clock_t start, end;
    start = clock();

    int minCost = matrixChainMemoized(p, 1, n);
    
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Minimum number of multiplications: %d\n", minCost);

    printf("Optimal Parenthesization: ");
    printOptimalParenthesis(1, n);
    printf("\n");

    printf("Time taken for execution: %f seconds\n", time_taken);

    return 0;
}
