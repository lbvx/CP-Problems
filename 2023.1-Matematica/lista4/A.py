x = int(input())
res = 1
p = 2

for b in range(2, 33):
    while b**p <= x:
        p += 1
    
    if p > 2:
        res = max(res, b**(p-1))
    b += 1
    p = 2
    
print(res)
