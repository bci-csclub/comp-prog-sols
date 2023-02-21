s = input()
n = int(input())
m = int(input())
grid = [list(input().split()) for i in range(n)]

charToPos = [-1]*128
for i in range(len(s)):
    charToPos[ord(s[i])] = i

MOVES = [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]
ans = 0

for x in range(n):
    for y in range(m):
        pos = charToPos[ord(grid[x][y])]
        if pos == -1: continue

        isPref = [False]*8
        isSuf = [False]*8

        for d in range(8):
            dx, dy = MOVES[d]

            isPref[d] = pos > 0
            x1, y1 = x, y
            for i in range(pos-1, -1, -1):
                x1 += dx; y1 += dy
                if x1 < 0 or y1 < 0 or x1 >= n or y1 >= m or grid[x1][y1] != s[i]: isPref[d] = False

            isSuf[d] = pos < len(s)-1
            x1, y1 = x, y
            for i in range(pos+1, len(s)):
                x1 += dx; y1 += dy
                if x1 < 0 or y1 < 0 or x1 >= n or y1 >= m or grid[x1][y1] != s[i]: isSuf[d] = False

        for d in range(8):
            ans += isPref[d] and isSuf[(d+2) % 8]
            ans += isPref[d] and isSuf[(d-2) % 8]
            ans += isSuf[d] and pos == 0

print(ans)
