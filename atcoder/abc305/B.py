# ABCDEFG

distances = {
    'A': 3,
    'B': 1,
    'C': 4,
    'D': 1,
    'E': 5,
    'F': 9,
}

def main():
    p, q = input().split()

    if q < p:
        p, q = q, p

    dist = 0
    while p != q:
        dist += distances[p]
        p = chr(ord(p) + 1)

    print(dist)

if __name__ == '__main__':
    main()
