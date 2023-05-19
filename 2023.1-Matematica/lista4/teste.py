MAX_ULL = 18_446_744_073_709_551_615*2

k = 40
res = 1
pot = 1
while (pot <= MAX_ULL):
    res += 1
    pot = res**k

N = res - 2
Nm1 = N + 1
print(f'N={N} N+1={Nm1}')
print(f'N**{k}={N**k} (N+1)**{k}={Nm1**k}')
