t = int(input())

for _ in range(t):
    n = int(input())
    count = {str(x): 0 for x in range(10)}
    nums = range(1, n + 1)

    for i in nums:
        for d in str(i):
            count[d] += 1

    print(*count.values())
