# ROT N 
def main():
    n = int(input())
    s = input()

    ns = [chr(((ord(c) - ord('A') + n) % 26) + ord('A')) for c in s]
    print(*ns, sep='')

if __name__ == '__main__':
    main()
