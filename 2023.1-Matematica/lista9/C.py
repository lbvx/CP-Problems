# Leading and Trailing
from math import log10, floor

def main():
    t = int(input())
    for _ in range(t):
        n, k = (int(i) for i in input().split())

        leading = 1
        digits = 1 + floor(k*log10(n))

        leading = floor(pow(10, k*log10(n) - digits + 3))

        trailing = pow(n % 1000, k, 1000)
        print(f'{leading:03}...{trailing:03}')

if __name__ == '__main__':
    main()
