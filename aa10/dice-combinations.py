n = int(input())

def subtrai(n):
    dp = [0]*(n+1)
    dp[n] = 1

    for dps in range(n, -1, -1):
        for i in range(1, 7):
            if dps - i >= 0:
                dp[dps - i] += dp[dps]
                dp[dps - i] %= (10**9 + 7)

    return dp[0]

print(subtrai(n))
