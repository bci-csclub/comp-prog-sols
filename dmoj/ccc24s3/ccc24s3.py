import sys

n = int(input())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))

blks = [[0, 0]]
for i in range(n):
    if brr[i] == brr[blks[-1][0]]:
        blks[-1][1] = i
    else :
        blks.append([i, i])

m = len(blks)
a_pos = []
blk_ind = 0

for i in range(n):
    if blk_ind < m and arr[i] == brr[blks[blk_ind][0]]:
        a_pos.append(i)
        blk_ind += 1

if blk_ind != len(blks):
    print('NO')
    sys.exit()

ans = []

for i in range(m):
    p = a_pos[i]
    l, r = blks[i]
    if p > l:
        ans.append(('L', l, p))

for i in range(m-1, -1, -1):
    p = a_pos[i]
    l, r = blks[i]
    if p < r:
        ans.append(('R', p, r))

print('YES')
print(len(ans))

for ch, l, r in ans:
    print(ch, l, r)
