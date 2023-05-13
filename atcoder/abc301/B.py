# Fill the Gaps
def main():
    n = int(input())
    s = [int(i) for i in input().split()]

    for i in range(len(s) - 1):
        print(s[i], end=' ')
        if s[i + 1] - s[i] > 1:
            for c in range(s[i] + 1, s[i + 1]):
                print(c, end=' ')
        elif s[i + 1] - s[i] < 1:
            for c in range(s[i] - 1, s[i + 1], -1):
                print(c, end=' ')

    print(s[-1])

if __name__ == '__main__':
    main()
