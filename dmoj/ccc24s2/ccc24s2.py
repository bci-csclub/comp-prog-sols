t, n = map(int, input().split())
for i in range(t):
    s = input()
    freq = [0]*128
    for ch in s:
        freq[ord(ch)] += 1
    is_heavy = [freq[ord(ch)] > 1 for ch in s]
    print("FT"[all(is_heavy[i] != is_heavy[i+1] for i in range(n-1))])
