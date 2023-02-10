from math import factorial as f

def main():
    digits = [0 for _ in range(10)] # ocorrencias de cada digito
    line = input()
    for c in line:
        if c != '/':
            digits[int(c)] += 1

    total = f(6)
    for d in digits:
        total //= f(d)

    print(total)

if __name__ == '__main__':
    main()
