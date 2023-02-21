n = int(input())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))

ans = 3*(sum(arr)+sum(brr))

for i in range(n-1):
    if arr[i] and arr[i+1]: ans -= 2
    if brr[i] and brr[i+1]: ans -= 2

for i in range(0, n, 2):
    if arr[i] and brr[i]: ans -= 2

print(ans)
