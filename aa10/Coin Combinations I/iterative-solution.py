_, x = map(int, input().split())
cs = [int(n) for n in input().split()]

dp = [0] * (x + 1)
dp[0] = 1

# Iteratividade
for i in range(cs[0], x + 1):
    for c in cs:
        if i - c >= 0:
            dp[i] = (dp[i] + dp[i - c]) % 1000000007

print(dp[x])
