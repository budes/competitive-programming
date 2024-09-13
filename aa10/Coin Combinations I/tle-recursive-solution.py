import sys
sys.setrecursionlimit(10**6+1)

_, x = map(int, input().split())

c = [int(n) for n in input().split()]

dp = [0] * (x + 1)
dp[0] = 1

def recursividade(dp, moedas, soma, x):
    for moeda in moedas:
        if moeda + soma == x: dp[x] += 1; return 1
        if moeda + soma < x:
            dp[moeda + soma] +=recursividade(dp, moedas, soma + moeda, x)
            dp[moeda + soma] %= 10**9 + 7

    return dp[soma]

print(recursividade(dp, c, 0, x))
