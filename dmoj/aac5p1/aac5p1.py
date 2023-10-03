n = int(input())
arr = list(map(int, input().split()))

num_even = 0
num_odd = 0
for a in arr:
    if a % 2 == 1:
        num_odd += 1
    else:
        num_even += 1

print(num_even//2 + num_odd//2)
