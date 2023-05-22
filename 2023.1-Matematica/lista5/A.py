# AtCoDeer and Election Report
from decimal import Decimal
from math import ceil

def main():
    n = int(input())
    ratios = []
    for _ in range(n):
        ratios.append(tuple(Decimal(i) for i in input().split()))

    res = list(ratios.pop(0))
    for r in ratios:
        prod = ceil(max(res[0] / r[0], res[1] / r[1]))
        res[0] = prod*r[0]
        res[1] = prod*r[1]

    print(sum(res))

if __name__ == '__main__':
    main()
