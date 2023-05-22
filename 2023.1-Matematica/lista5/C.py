# Simple division
from math import gcd

def main():
    xs = [int(i) for i in input().split()]
    xs.pop()
    while len(xs) > 0:
        xs = list(map(lambda x: x - xs[0], xs))
        d = gcd(*xs)
        
        print(d)
        xs = [int(i) for i in input().split()]
        xs.pop()

if __name__ == '__main__':
    main()
