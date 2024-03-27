# Adjacent Product

def main():
    n = int(input())
    a = [int(x) for x in input().split()]

    b = [x * y for x, y in zip(a[:-1], a[1:])]

    print(*b, sep=' ')

if __name__ == '__main__':
    main()
