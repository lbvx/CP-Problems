def main():
    m, j, t = (int(i) for i in input().split())
    m *= 100 # centavos
    res = m

    for _ in range(t):
        res *= 100 + j
        res //= 100

    print(f'{res // 100}.{res % 100:02}')

if __name__ == '__main__':
    main()