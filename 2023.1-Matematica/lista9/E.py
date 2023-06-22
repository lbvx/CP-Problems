# Iterated Linear Function 
MAX = 10**9 + 7

def main():
    a, b, n, x = [int(i) for i in input().split()]

    if a == 1:
        res = x + b * n
    else:
        an = pow(a, n, MAX)

        p1 = an - 1
        p2 = pow(a - 1, MAX - 2, MAX)
        # p2 = a - 1

        # res = an*x + ((b * (p1 // p2)) % MAX)
        res = an*x + ((p1 * p2) % MAX) * b

    res %= MAX
    print(res)

if __name__ == '__main__':
    main()
