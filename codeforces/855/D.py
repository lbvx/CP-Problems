def main():
    t = int(input())
    for _ in range(t):
        input() # n
        s = input()
        diff = set()
        for i in range(len(s) - 1):
            new = s[0:i] + s[i+2:]
            diff.add(new)

        print(len(diff))
        del diff

if __name__ == '__main__':
    main()