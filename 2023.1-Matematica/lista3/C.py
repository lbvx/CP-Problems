def main():
    try:
        while True:
            x = int(input())
            coefficients = [int(i) for i in input().split()]

            res = 0
            for i in range(len(coefficients) - 1):
                n = len(coefficients) - i - 1
                res += n * (x**(n - 1)) * coefficients[i]

            print(res)
    except EOFError:
        pass

if __name__ == '__main__':
    main()
