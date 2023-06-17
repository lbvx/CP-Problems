# Base 2
def main():
    a = input()
    a = a.replace(' ', '')

    a = a[::-1]
    # print(a)

    print(int(a, 2))

if __name__ == '__main__':
    main()
