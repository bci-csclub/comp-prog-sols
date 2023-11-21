import sys
input = sys.stdin.readline

n = int(input())
dp = [[0]*(n+1) for i in range(n+1)]

for i in range(1, n+1):
    arr = list(map(int, input().split()))
    for j in range(1, i+1):
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + arr[j-1]

print(max(dp[n]))
