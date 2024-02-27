import sys
input = sys.stdin.readline

n = int(input())
m = int(input())

grid = [input() for i in range(n)]
vis = [[False]*m for i in range(n)]

ans = 0
MOVES = ((0, 1), (1, 0), (0, -1), (-1, 0))

qu = []
ql = 0

sx, sy = int(input()), int(input())
qu.append((sx, sy))
vis[sx][sy] = True

while ql < len(qu):
    x1, y1 = qu[ql]; ql += 1
    if grid[x1][y1] == 'S': ans += 1
    if grid[x1][y1] == 'M': ans += 5
    if grid[x1][y1] == 'L': ans += 10

    for dx, dy in MOVES:
        x2 = x1 + dx
        y2 = y1 + dy
        if x2 < 0 or x2 >= n or y2 < 0 or y2 >= m or grid[x2][y2] == '*' or vis[x2][y2]: continue
        vis[x2][y2] = True
        qu.append((x2, y2))

print(ans)
