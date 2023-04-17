h = set()
n = [int(x) for x in input().split()]

rep = 0
for i in n:
    if i in h:
        rep += 1
    else:
        h.add(i)

print(rep)
