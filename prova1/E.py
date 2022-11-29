b, d = [int(e) for e in input().split()]
num = int(input(), 2)

inv = 1 << b
print("{0:b}".format(inv - num))
