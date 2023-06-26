# Holiday Of Equality 
def main():
    n = int(input())
    a = [int(i) for i in input().split()]

    m = max(a)
    print(sum(m - x for x in a))

if __name__ == '__main__':
    main()
