# Odd Divisor
def odd_divisor(n):
    while n > 1:
        if n & 1:
            return True
        n //= 2

    return False

def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        print('YES' if odd_divisor(n) else 'NO')


if __name__ == '__main__':
    main()
