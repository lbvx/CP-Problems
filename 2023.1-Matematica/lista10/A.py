# Task Scheduling Problem 
def main():
    a = [int(i) for i in input().split()]
    a.sort()
    total = 0
    for i in range(1, len(a)):
        total += abs(a[i] - a[i - 1])

    print(total)

if __name__ == '__main__':
    main()
