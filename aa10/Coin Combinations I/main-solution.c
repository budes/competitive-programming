#include <stdio.h>

int main() {
    // Input
    int n, x;
    scanf("%d %d\n", &n, &x);

    int coin[n];
    for (int i = 0; i < n; i++) { scanf("%d", &coin[i]); }

    //DP creation
    int dp[x + 1];
    for (int i = 0; i <= x; i ++) { dp[i] = 0; }
    dp[0] = 1;

    int coin_value;
    //Iteration through the dp
    for (int i_dp = 0; i_dp <= x; i_dp++) {
        for (int i_coin = 0; i_coin < n; i_coin ++) {
            coin_value = coin[i_coin];
            if (i_dp - coin_value >= 0) {
                dp[i_dp] = (dp[i_dp] + dp[i_dp - coin_value]) % 1000000007;
            }
        }
    }

    printf("%d", dp[x]);
    return 0;
}
