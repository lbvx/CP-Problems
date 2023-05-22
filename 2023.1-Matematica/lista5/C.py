# Simple division

def divisors(n):
    # get factors and their counts
    factors = {}
    nn = n
    i = 2
    while i*i <= nn:
        while nn % i == 0:
            factors[i] = factors.get(i, 0) + 1
            nn //= i
        i += 1
    if nn > 1:
        factors[nn] = factors.get(nn, 0) + 1

    primes = list(factors.keys())

    # generates factors from primes[k:] subset
    def generate(k):
        if k == len(primes):
            yield 1
        else:
            rest = generate(k+1)
            prime = primes[k]
            for factor in rest:
                prime_to_i = 1
                # prime_to_i iterates prime**i values, i being all possible exponents
                for _ in range(factors[prime] + 1):
                    yield factor * prime_to_i
                    prime_to_i *= prime

    for factor in generate(0):
        yield factor

def main():
    xs = [int(i) for i in input().split()]
    xs.pop()
    while len(xs) > 0:
        # print(xs)
        s = min(xs)
        xs = list(map(lambda x: x - s, xs))
        b = max(xs)
        d = 1

        for i in divisors(b):
            if len(set(map(lambda x: x % i, xs))) == 1:
                d = i
        
        print(d)
        xs = [int(i) for i in input().split()]
        xs.pop()


if __name__ == '__main__':
    main()
