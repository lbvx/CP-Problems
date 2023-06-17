# Echo
def main():
    n = input()
    s = input()

    ss = ''
    for c in s:
        ss += c + c

    print(ss)

if __name__ == '__main__':
    main()
