import sys

s1 = input()
s2 = input()

if len(s1) == len(s2):
    for i in range(len(s1)):
        if s1[i] != s2[i]:
            print(s1[i], s2[i])
            print('-')
            sys.exit()

for i in range(26):
    silent_char = chr(ord('a')+i)
    new_s1 = s1.replace(silent_char, '')
    if len(new_s1) != len(s2):
        continue
    bad_pairs = set()
    for j in range(len(s2)):
        if new_s1[j] != s2[j]:
            bad_pairs.add((new_s1[j], s2[j]))
    if len(bad_pairs) == 1:
        ch1, ch2 = list(bad_pairs)[0]
        print(ch1, ch2)
        print(silent_char)
        break
