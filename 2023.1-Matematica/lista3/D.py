def main():
    try:
        while True:
            n = int(input())
            print(n**2 * (n+1)**2 // 4)
    except EOFError:
        pass

if __name__ == '__main__':
    main()
