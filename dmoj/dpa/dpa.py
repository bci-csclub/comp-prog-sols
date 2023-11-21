import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

dp = [0]*n
for i in range(1, n):
    if i == 1:
        dp[i] = dp[i-1] + abs(arr[i]-arr[i-1])
    else:
        dp[i] = min(dp[i-1] + abs(arr[i]-arr[i-1]), dp[i-2] + abs(arr[i]-arr[i-2]))

print(dp[n-1])
