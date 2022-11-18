A = [1, 3, 5, 7, 8, 10, 12]
B = [4, 6, 9, 11]
C = [2]

T = [A, B, C]

def check(x, y, V):
    for v in V:
        if x in v:
            a = v
            break

    if y in a:
        return True
    return False

def main():
    x, y = [int(i) for i in input().split()]

    print("Yes" if check(x, y, T) else "No")

if __name__ == '__main__':
    main()
