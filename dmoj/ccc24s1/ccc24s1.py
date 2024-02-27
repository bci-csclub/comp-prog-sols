n = int(input())
arr = [int(input()) for i in range(n)]
print(2*sum(arr[i] == arr[i+n//2] for i in range(n//2)))
