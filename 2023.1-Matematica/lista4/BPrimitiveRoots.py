import json

def main():
    roots = {}
    with open('primes.txt', 'r') as f:
        for p in map(int, f):
            print('testando', p)
            total = 0
            for x in range(1, p):
                if (x**(p - 1) - 1) % p != 0:
                    continue

                for exp in range(p - 2, 0, -1):
                    if (x**exp - 1) % p == 0:
                        break
                else:
                    total += 1
            roots[p] = total
    with open('primitiveRoots.json', 'w') as f:
        json.dump(roots, f)

if __name__ == '__main__':
    main()
