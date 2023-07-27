def main():
    g, d, r = (float(i) for i in input().split())

    x = r * 1000.0 / g / (1.0 - d / 100.0)
    print(x)

if __name__ == '__main__':
    main()