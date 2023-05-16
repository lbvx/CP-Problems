# Big Number
from math import log10, floor

# nDigitos = ceil(log10(x))
def factorial_digits(x):
    sum = 1.0
    for i in range(x, 1, -1):
        sum += log10(i)

    return floor(sum)

def main():
    n = int(input())
    for _ in range(n):
        x = int(input())
        print(factorial_digits(x))

if __name__ == '__main__':
    main()
