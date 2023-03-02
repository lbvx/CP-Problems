import re

pattern = "[mM]+[eE]+[oO]+[wW]+"
t = int(input())

for _ in range(t):
    input()
    s = input()
    if re.fullmatch(pattern, s):
        print('YES')
    else:
        print('NO')
