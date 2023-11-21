import sys
input = sys.stdin.readline

d = int(input())
n = int(input())

clubs = [int(input()) for i in range(n)]

INF = 1 << 30
dp = [INF]*(d+1)

dp[0] = 0
for pos in range(1, d+1):
    for a in clubs:
        if a <= pos:
            dp[pos] = min(dp[pos], dp[pos-a] + 1)

if dp[d] == INF:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in " + str(dp[d]) + " strokes.")
