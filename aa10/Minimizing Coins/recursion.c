#include <stdio.h>

int recursion (int coins[], int dp[], int n, int x, int pos) {
    for (int c = 0; c < n; c ++) {
        if (pos + coins[c] <= x) {
            if (dp[pos] < dp[pos + coins[c]]) {
                dp[pos + coins[c]] = dp[pos] + 1;
            }
            if (pos + coins[c] < x) {
                recursion(coins, dp, n, x, pos + coins[c]);
            }
        }
    }
    if (dp[x] < x + 1) { return dp[x]; }

    return -1;
}

int main() {
    int n, x;
    scanf("%d %d\n", &n, &x);

    int coins[n];
    for (int i = 0; i < n; i++){ scanf("%d", &coins[i]); }

    int dp[x + 1];
    for (int i = 0; i < (x+1); i ++) { dp[i] = x; }
    dp[x]++;
    dp[0] = 0;

    int least = recursion(coins, dp, n, x, 0);
    printf("%d", least);
}
