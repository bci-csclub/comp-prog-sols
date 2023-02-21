n, m, r, c = map(int, input().split())

swapped = False
if m == c:
    n, m = m, n
    r, c = c, r
    swapped = True

grid = [['a']*m for i in range(n)]

def solve():
    if n == r and m == c: return True

    if n != r:
        for i in range(n-r): grid[i][0] = 'b'
        for i in range(m-c): grid[0][i] = 'b'
        grid[0][0] = 'c'
    else:
        for i in range((m-c)//2): grid[0][i] = grid[0][m-i-1] = 'b'
        if (m-c) % 2 == 1:
            if m % 2 == 1: grid[0][m//2] = 'b'
            else: return False
    return True

if not solve(): print("IMPOSSIBLE")
elif swapped:
    for i in range(m):
        for j in range(n):
            print(grid[j][i], end='')
        print()
else:
    for i in range(n):
        for j in range(m):
            print(grid[i][j], end='')
        print()
