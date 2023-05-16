# Power of Cryptography

def binary_search(n, p, l, r):
    m = (r + l) // 2
    result = m**n
    if result == p:
        return m
    if result > p:
        return binary_search(n, p, l, m - 1)
    
    return binary_search(n, p, m + 1, r)

def main():
    try:
        while True:
                n = int(input())
                p = int(input())
                l = 1
                r = p // n + 1
                ans = binary_search(n, p, l, r)
                print(ans)

    except EOFError:
        pass

if __name__ == '__main__':
    main()
