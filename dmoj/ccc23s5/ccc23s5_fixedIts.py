n = int(input())
PW = 3**18

def check(x):
    for i in range(150):
        d = x//n
        x -= d*n
        if d == 1 and x: return False
        x *= 3
    return True

def solve(l, r):
    dif = r-l
    a = (n*l + PW-1)//PW
    b = n*r//PW + 1
    if a == b: return

    if dif > 1:
        solve(l, l + dif//3)
        solve(r - dif//3, r)
    else:
        for i in range(a, b):
            if check(i): print(i)

solve(0, PW)
