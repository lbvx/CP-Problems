import itertools

def main():
    homens = []
    mulheres = []
    m, n = [int(i) for i in input().split()]

    for _ in range(m):
        p = input().split()
        if p[1] == 'M':
            homens.append(p[0])
        else:
            mulheres.append(p[0])

    if n == 4:
        total = list(itertools.product(itertools.combinations(homens, 2), itertools.combinations(mulheres, 2)))

    elif n == 5:
        total = list(itertools.product(itertools.combinations(homens, 3), itertools.combinations(mulheres, 2)))
        total.extend(list(itertools.product(itertools.combinations(homens, 2), itertools.combinations(mulheres, 3))))

    elif n == 6:
        total = list(itertools.product(itertools.combinations(homens, 3), itertools.combinations(mulheres, 3)))
        total.extend(list(itertools.product(itertools.combinations(homens, 2), itertools.combinations(mulheres, 4))))
        total.extend(list(itertools.product(itertools.combinations(homens, 4), itertools.combinations(mulheres, 2))))

    sts = []
    for t in total:
        n = []
        n.extend(t[0])
        n.extend(t[1])
        n.sort()
        sts.append(','.join(n))

    sts.sort()
    print(len(total))
    for s in sts:
        print(s)

if __name__ == '__main__':
    main()