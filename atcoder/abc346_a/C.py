# Σ

def main():
    n, k = (int(x) for x in input().split())

    a_set = set()
    
    for sa in input().split():
        a = int(sa)

        if a <= k:
            a_set.add(a)

    s = (1 + k) * k // 2

    print(s - sum(a_set))

if __name__ == '__main__':
    main()
