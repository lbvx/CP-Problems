def main():
    n = int(input())
    s = input().replace('1', 'l')
    s = s.replace('0', 'o')
    t = input().replace('1', 'l')
    t = t.replace('0', 'o')
    print('Yes' if s == t else 'No')

if __name__ == '__main__':
    main()
