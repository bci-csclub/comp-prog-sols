n = int(input())
PW = 3**18

MN = int(1e9)
bits = bytearray(MN>>3)
to_clear = []

def check(x):
    global bits
    for a in to_clear:
        bits[a>>3] ^= 1 << (a&7)
    to_clear.clear()

    while True:
        d = x//n
        x -= d*n
        if d == 1 and x: return False
        if bits[x>>3] & (1<<(x&7)): return True
        bits[x>>3] |= 1<<(x&7)
        to_clear.append(x)
        x *= 3

def solve(l, r):
    dif = r-l
    if dif > 1:
        solve(l, l + dif//3)
        solve(r - dif//3, r)
    else:
        a = (n*l + PW-1)//PW
        b = n*r//PW + 1
        for i in range(a, b):
            if check(i): print(i)

solve(0, PW)
