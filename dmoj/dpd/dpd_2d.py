import sys
input = sys.stdin.readline

n, mxW = map(int, input().split())
dp = [[0]*(mxW+1) for i in range(n+1)]

for i in range(n):
    w, v = map(int, input().split())
    for j in range(mxW+1):
        if j < w: dp[i+1][j] = dp[i][j]
        else: dp[i+1][j] = max(dp[i][j], dp[i][j-w] + v)

print(max(dp[n]))
