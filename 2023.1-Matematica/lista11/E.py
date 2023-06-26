# Yet Another Two Integers Problem 
def main():
    t = int(input())
    for _ in range(t):
        a, b = (int(i) for i in input().split())
        print(1 + (abs(a - b) - 1) // 10)

if __name__ == '__main__':
    main()
