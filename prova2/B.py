from math import factorial

def nck(n, k):
    return factorial(n) // (factorial(k) * factorial(n - k))

def main():
    N, R = [int(i) for i in input().split()]
    print(nck(N, 2) - R)

if __name__ == '__main__':
    main()
