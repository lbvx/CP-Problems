input()
c = [int(i) for i in input().split()]
c.sort()
print(c[-1] - c[0])
