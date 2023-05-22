# LCM Cardinality
from math import lcm

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
    n = int(input())
    while n != 0:
        divs = list(divisors(n))
        total = 0
        
        # print(list(divs))

        for i in range(1, len(divs) - 1):
            for j in range(i, len(divs) - 1):
                if lcm(divs[i], divs[j]) == n:
                    total += 1

        total += len(divs)
        print(n, total)

        n = int(input())

if __name__ == '__main__':
    main()
