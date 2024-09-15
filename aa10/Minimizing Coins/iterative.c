#include <stdio.h>

int iterative(int coins[], int dp[], int x, int n) {

    for (int pos = 0; pos <= x; pos ++) {
        if (dp[pos] < x) {
            for (int c_pos = 0; c_pos < n; c_pos ++) {
                if (pos + coins[c_pos] <= x) {
                    if (dp[pos] + 1 < dp[pos + coins[c_pos]]) {
                        dp[pos + coins[c_pos]] = dp[pos] + 1;
                    }
                }
            }
        }
    }

    if (dp[x] == (x + 1)) { return -1; }

    return dp[x];
}

int main() {
    int n, x;
    scanf("%d %d\n", &n, &x);

    int coins[n];
    for (int i = 0; i < n; i++){ scanf("%d", &coins[i]); }

    int dp[x + 1];
    for (int i = 0; i < (x+1); i ++) { dp[i] = x + 1; }
    dp[0] = 0;

    int least = iterative(coins, dp, x, n);
    printf("%d", least);
}
