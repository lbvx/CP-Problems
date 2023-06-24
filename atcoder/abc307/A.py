# Weekly Records 
def main():
    weeks = int(input())
    a = [int(i) for i in input().split()]
    for w in range(weeks):
        print(sum(a[7*w:7*(w+1)]), end=' ')
    print()

if __name__ == '__main__':
    main()
