s = input()
bs = s.count('B')

for _ in range(bs):
    i = s.find('B')
    if i == 0:
        s = s[1:]
    else:
        s = s[:i-1] + s[i+1:]

print(s)
