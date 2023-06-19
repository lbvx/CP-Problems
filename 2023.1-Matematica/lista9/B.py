# Big Mod
def main():
    try:
        while True:
            b = int(input())
            p = int(input())
            m = int(input())
            print(pow(b, p, m))
            input()
    except EOFError:
        pass

if __name__ == '__main__':
    main()