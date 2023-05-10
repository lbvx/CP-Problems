def main():
    num = input()
    z = num.find('0')
    if z == -1:
        print(num[:-1])
    else:
        print(num[:z] + num[z+1:])

if __name__ == '__main__':
    main()
