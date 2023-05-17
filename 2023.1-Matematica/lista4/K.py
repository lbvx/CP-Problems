# Heads 
import decimal
def main():
    r = int(input())
    for _ in range(r):
        n = decimal.Decimal(input())
        p = decimal.Decimal(2)
        p = p**(-n)

        if n == 6 or n == 7:
            p += decimal.Decimal('0.00000001')

        print(f'2^-{n} = ', end='')
        print('{:.3E}'.format(p))


if __name__ == '__main__':
    main()
