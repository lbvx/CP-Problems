# The Cat in the Hat
from decimal import Decimal

def msb(x):
    b = 0
    while x > 0:
        x >>= 1
        b += 1
    return b

# def find_N_k(height, workers):
#     if workers == 1:
#         return (1, msb(height) - 1)
    
#     if workers + 1 == height:
#         return (workers, 1)

#     sm = min(height, workers)
#     limit = Decimal(sm)
#     half = Decimal('0.5')
#     limit **= half
#     limit = round(limit)
#     while True:
#         k = 2
#         res = limit*limit
#         while res < sm:
#             res *= limit
#             k += 1
#         if res == height:
#             N = round(height**(1 / Decimal(k)) - 1)
#             if N**k == workers:
#                 return round(N), k
#         if res == workers:
#             N = round(workers**(1 / Decimal(k)))
#             if (N + 1)**k == height:
#                 return round(N), k
#         limit -= 1

def approximate(a, b):
    return abs(a - b) < Decimal('1E-6')

# Altura = (N+1)^k e qtd_workers = N^k => encontrar N e k
def find_N_k(height, workers):
    if workers == 1:
        return (1, msb(height) - 1)
    
    if workers + 1 == height:
        return (workers, 1)

    d_height = Decimal(height)
    d_workers = Decimal(workers)

    k = Decimal(2)
    while True:
        inv_k = 1 / k
        N = d_workers**inv_k
        # if k == 40:
        #     # print(f'k={k}\nworkers={d_workers}\nheight={d_height}\nN={N}\nN^k={N**k}\n(N+1)^k={(N+1)**k}')
        if approximate((N+1)**k, d_height):
            return round(N), round(k)
        
        N = d_height**inv_k - 1
        if approximate(N**k, d_workers):
            return round(N), round(k)
        
        k += 1

def main():
    initial_cat_height, n_workers = [int(i) for i in input().split()]
    while initial_cat_height > 0:
        N, k = find_N_k(initial_cat_height, n_workers)

        if N == 1:
            not_workers = k*N
        else:
            not_workers = (1 - N**(k + 1)) // (1 - N) - n_workers

        cat_stack = 0
        for i in range(k+1):
            cat_stack += round(N**i * initial_cat_height / (N + 1)**i)

        print(N, k)
        print(not_workers, cat_stack)

        initial_cat_height, n_workers = [int(i) for i in input().split()]

if __name__ == '__main__':
    main()
