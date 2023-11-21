import sys
input = sys.stdin.readline

n, mxW = map(int, input().split())
oldDp = [0]*(mxW+1)
newDp = [0]*(mxW+1)

for i in range(n):
    w, v = map(int, input().split())
    oldDp = newDp.copy()
    for j in range(mxW+1):
        if j < w: newDp[j] = oldDp[j]
        else: newDp[j] = max(oldDp[j], oldDp[j-w] + v)

print(max(newDp))
