import sys
input = sys.stdin.readline

n, mxW = map(int, input().split())
dp = [0]*(mxW+1)

for i in range(n):
    w, v = map(int, input().split())
    for j in range(mxW, w-1, -1):
        dp[j] = max(dp[j], dp[j-w] + v)

print(dp[mxW])
