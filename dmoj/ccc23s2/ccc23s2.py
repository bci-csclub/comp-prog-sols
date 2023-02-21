INF = int(1e9)

n = int(input())
arr = list(map(int, input().split()))
ans = [INF]*(n+1)

def iterOut(l, r):
    cur = 0
    while l > 0 and r < n-1:
        l -= 1
        r += 1
        cur += abs(arr[l] - arr[r])
        ans[r-l+1] = min(ans[r-l+1], cur)

# odd length subarrays
ans[1] = 0
for i in range(n):
    iterOut(i, i)

# even length subarrays
for i in range(n-1):
    iterOut(i+1, i)

print(*ans[1:])
