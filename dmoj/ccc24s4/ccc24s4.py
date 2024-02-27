import sys
input = sys.stdin.readline

n, m = map(int, input().split())
arr = [(0, 0)]*(m+m+1)
nxt = [0]*(m+m+1)
head = [0]*n
ai = 1

for i in range(m):
    a, b = map(int, input().split())
    a -= 1; b-= 1

    nxt[ai] = head[a]
    arr[ai] = (b, i)
    head[a] = ai
    ai += 1

    nxt[ai] = head[b]
    arr[ai] = (a, i)
    head[b] = ai
    ai += 1

ans = ['G']*m
vis = [False]*n
dep = [0]*n

stk = []

for i in range(n):
    if not vis[i]:
        vis[i] = True
        stk.append(i)

        while len(stk) > 0:
            n1 = stk[-1]
            if head[n1] == 0:
                stk.pop()
                continue

            n2, e = arr[head[n1]]
            head[n1] = nxt[head[n1]]
            if not vis[n2]:
                vis[n2] = True
                stk.append(n2)
                dep[n2] = dep[n1] ^ 1
                ans[e] = 'RB'[dep[n1]]

print(''.join(ans))
