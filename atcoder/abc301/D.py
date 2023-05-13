# Bitmask
def main():
    s = input()
    n = int(input())

    snum = int(s.replace('?', '0'), 2)
    
    i = len(s) - 1
    while i >= 0:
        if s[len(s) - i - 1] == '?':
            if snum | (1 << i) <= n:
                snum |= 1 << i
        i -= 1

    print(snum if snum <= n else -1)

if __name__ == '__main__':
    main()
