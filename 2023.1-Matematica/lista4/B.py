def main():
    p = int(input())
    total = 0
    for x in range(1, p):
        if (x**(p - 1) - 1) % p != 0:
            continue

        for exp in range(p - 2, 0, -1):
            if (x**exp - 1) % p == 0:
                break
        else:
            total += 1

    print(total)

if __name__ == '__main__':
    main()
